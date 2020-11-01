// Solution to Project Euler problem 49

#include <iostream>
#include <chrono>

#include <math.h>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

/*
Solution approach
generate all primes to cap
loop the primes
map ordered digits of numbers to ordered-sets containing themselves
loop the ordered-sets and check their size >= 3
if so double-loop pairs, looking for third
*/

unsigned long long solution(){
	int cap = 10000;
	int len = 4;

	unsigned long long second_place = (unsigned long long) cap;
	unsigned long long third_place = second_place * second_place;

	// generate primes
	std::set<int> primes = {2};

	for (int num=3; num <cap; num+=2){
		// Find prime factor
		bool prime_check = true;
		for (auto it_prime = primes.begin(); it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes.insert(num);
	}
	
	// create perm-sets
	std::map<int,std::set<int>> perm_sets;
	for(auto it_prime = primes.begin(); it_prime != primes.end(); it_prime++){
		if( 4 != 1 + (int)log10(*it_prime)) continue;
		// generate perm int
		int temp = *it_prime;
		std::vector<int> digs;
		while(temp){
			digs.push_back(temp%10);
			temp /= 10;
		}
		std::sort(digs.begin(),digs.end());
		for(auto it_dig=digs.begin(); it_dig != digs.end(); it_dig++) temp = 10*temp + *it_dig;
		perm_sets[temp].insert(*it_prime);
	}

	// loop ordered pair for third
	for(auto it_key = perm_sets.begin(); it_key !=  perm_sets.end(); it_key++){
		//std::cout << it_key->first << " : ";
		//for(auto it_num = it_key->second.begin(); it_num !=  it_key->second.end(); it_num++) std::cout << *it_num << ",";
		//std::cout << std::endl;
		
		if(it_key->second.size() < 3) continue;
		for(auto it_first = it_key->second.begin(); it_first !=  it_key->second.end(); it_first++){
			for(auto it_second = it_first; it_second !=  it_key->second.end(); it_second++){
				if(it_first == it_second) continue;
				if(it_key->second.find(2*(*it_second) - (*it_first)) != it_key->second.end()) {
					//std::cout << "FOUND: " << (*it_first) << " -> " << (*it_second) << " -> " << (2*(*it_second) - (*it_first)) << std::endl;
					if(*it_first != 1487) return ((unsigned long long) 2*(*it_second) - (*it_first)) + ((unsigned long long) *it_second) * second_place 
						+ ((unsigned long long) *it_first) * third_place;
				}
			}
		}
		
	}

	return 0;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
