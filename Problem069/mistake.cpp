// Solution to Project Euler problem 69

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <map>
#include <set>

/*
Solution approach
-Compute divisors
-Memoize sub-solutions for speedup
-Requires keeing track of primes
-On each compute the totient, and ratio

See Problem 23 for divisor finding
*/


int solution(){ 
	int target = 10;

	std::vector<std::map<int,int>> divisors;
	std::list<int> primes;

	// Init
	primes.push_back(2);
	divisors.push_back(std::map<int,int>{{2,1}});

	for (int n=3; n <= target; n++){
		// Find prime factor
		bool prime_check = true;
		auto it_prime = primes.begin();
		for (; it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= n; ++it_prime) 
			prime_check = n % *it_prime;
		if (prime_check){
			primes.push_back(n);
			divisors.push_back({{n,1}});
		}
		else {
			// If isn't prime, add sub-solution with the factor in
			it_prime--;
			int factor = *it_prime;
			
			divisors.push_back(divisors[n/factor-2]);
			divisors.back()[factor]++;
		}
			// compute totient
			int total_divisors = 1;
			for(auto it = divisors.back().begin(); it != divisors.back().end(); it++) total_divisors *= it->second +1;
			int totient = n + 1 - total_divisors;
			std::cout << "phi(" << n << ") = " << totient << std::endl;
	}

	for(int i = 0; i < divisors.size(); i++){
		std::cout << (i+2) << " = ";
		for(auto it = divisors[i].begin(); it != divisors[i].end(); it++) std::cout << "(" << it->first << "^" << it->second << ")";
		std::cout << std::endl;
	}

	int result = 0;
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
