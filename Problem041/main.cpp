// Solution to Project Euler problem 41

#include <iostream>
#include <chrono>

#include <set>
#include <list>
#include <math.h>

/* 
use set for primes for faster searching
use sqrt for search
cache primes
*/


bool is_prime(long n, std::set<long> *primes){
	// check if in known primes
	if(primes->find(n) != primes->end()) return true;

	// check if factor known already
	bool prime_check = true;
	for (auto it_prime=primes->begin(); it_prime!=primes->end() &&  prime_check && (*it_prime)*(*it_prime) <= n; ++it_prime)
		 prime_check = n % *it_prime;
	if(!prime_check) return false;

	// generate primes until have enough to check primality
	for (long num = *(primes->rbegin()); num*num <= n; num += 2){
		prime_check = n % num;
		if(!prime_check) return false;

		bool sub_prime_check = true;
		for (auto it_prime=primes->begin(); it_prime!=primes->end() && sub_prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			sub_prime_check = num % *it_prime;
		if (sub_prime_check) primes->insert(num);
	}
	return true;
}

long gen_perms(long perm, long pos, std::set<long> digits, std::set<long> *primes){
	//std::cout << "checking: " << perm << std::endl;

	// explore other perms solutions
	long result = 0;
	if(!digits.empty()) {
		std::set<long> temp_digits = digits;
		for(auto dig_it = digits.begin(); dig_it != digits.end(); dig_it++){
			temp_digits.erase(*dig_it);
			long temp_perm = *dig_it * pos + perm;
			long temp_result = gen_perms(temp_perm, 10*pos, temp_digits, primes);
			temp_digits.insert(*dig_it);
			result = result > temp_result ? result : temp_result;
		}
	}
	else if(is_prime(perm,primes)){
		//std::cout << "candidate: " << perm << std::endl;
		return perm;
	}
	return result;
}


long solution(){ 
	std::set<long> primes = {2,3};
	std::set<long> digits;
	long n = 9;
	long result = 0;
	for(long dig=1; dig<=n; dig++){
		digits.insert(dig);
		//std::cout << "Searching with n = " << digits.size() << std::endl;
		long temp = gen_perms(0, 1, digits, &primes);
		result = result > temp ? result : temp;
	}
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
