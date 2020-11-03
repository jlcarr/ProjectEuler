// Solution to Project Euler problem 50

#include <iostream>
#include <chrono>

#include <set>
#include <vector>

/* 
generate primes and a running sum to n until an upper-bound length is achieved
iterate over len going down
i-j = len
sum[i] - sum[j] < n
start with j=0, i=len, and go up, generating primes as needed until sum[i] - sum[j] >= n
use is_prime function for speedup
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


long solution(){ 
	long n = 1000000;
	std::set<long> primes = {2};
	std::vector<long> prime_sum = {0,2};

	// generate initial primes
	for (long num = 3; prime_sum.back() < n; num += 2){
		bool prime_check = true;
		for (auto it_prime=primes.begin(); it_prime!=primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime)
			prime_check = num % *it_prime;
		if (prime_check) {
			primes.insert(num);
			prime_sum.push_back(num + prime_sum.back());
		}
	}

	//for(auto it_prime=prime_sum.begin(); it_prime!=prime_sum.end(); ++it_prime) std::cout << *it_prime << std::endl;

	// decrements max length
	for (int len = prime_sum.size()-1; len > 0; len--){
		// start searching range at the beginning
		int j = 0;
		long consecutive_sum = prime_sum[len + j] - prime_sum[j];
		while(consecutive_sum < n){
			// check if is a solution
			if(is_prime(consecutive_sum, &primes)) return consecutive_sum;
			
			// generate more primes if need be
			for (long num = *(primes.rbegin()); len + j == prime_sum.size()-1; num += 2){
				bool prime_check = true;
				for (auto it_prime=primes.begin(); it_prime!=primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime)
					prime_check = num % *it_prime;
				 if (prime_check) {
					primes.insert(num);
					prime_sum.push_back(num + prime_sum.back());
				}
			}

			// increment range start
			j++;
			consecutive_sum = prime_sum[len + j] - prime_sum[j];
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
