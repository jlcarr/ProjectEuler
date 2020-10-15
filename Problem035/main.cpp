// Solution to Project Euler problem 35

#include <iostream>
#include <chrono>

#include <set>
#include <math.h>

/* 
use set for primes for laster searching
*/

long solution(){ 
	int n = 1000000;

	// Build prime list
	std::set<int> primes = {2};
	for (int num=3; num<n; num+=2){
		bool prime_check = true;
		for (auto it_prime=primes.begin(); it_prime!=primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes.insert(num);
	}

	// check for circulars
	int count = 0;
	for (auto it_prime=primes.begin(); it_prime!=primes.end(); ++it_prime){
		int num_len = 1 + (int)log10(*it_prime);
		int len_pos = 1;
		for(int i=0; i<num_len-1; i++) len_pos *= 10;
		int circ = *it_prime;

		bool is_circ = true;
		for(int i=0; i<num_len-1 && is_circ; i++){
			int dig = circ%10;
			circ = circ/10 + dig*len_pos;
			is_circ = (primes.find(circ) != primes.end());
		}
		if(is_circ){ 
			count++;
			// std::cout << *it_prime << std::endl;
		}
	}
	return count;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
