// Solution to Project Euler problem 46

#include <iostream>
#include <chrono>

#include <math.h>
#include <set>

/*
Solution approach
gen primes by search odd numbers
if composite, search for difference with smaller squares is a prime
*/

int solution(){
	std::set<int> primes = {2,3};

	int num = 3;

	while(true){
		num += 2;

		// Find prime factor
		bool prime_check = true;
		for (auto it_prime = primes.begin(); it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes.insert(num);
		else {
			bool is_result = true;
			for(int sq = 1; 2*sq*sq < num && is_result; sq++) is_result = (primes.find(num - 2*sq*sq) == primes.end());
			if (is_result) return num;
		}
	}
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
