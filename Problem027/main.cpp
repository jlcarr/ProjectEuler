// Solution to Project Euler problem 27

#include <iostream>
#include <chrono>

#include <math.h>
#include <set>

/*
Solution approach
n=1000
generate all primes to sqrt(2*n^2+n)
keep in ordered set
loop b in primes<n
loop a simply in -n to n
count the cycle
*/

int solution(){
	int n = 1000;
	std::set<int> primes;

	primes.insert(2);

	for (int num=3; num <= (int) sqrt(2*n*n+n); num++){
		// Find prime factor
		bool prime_check = true;
		for (auto it_prime = primes.begin(); it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes.insert(num);
	}
	
	int max_a = -n;
	int max_b = 0;
	int max_len = 0;
	for(auto b = primes.begin(); b != primes.end() && *b <= n; b++){
		for(int a=-n+1; a<n; a++){
			int len = 0;
			for (int num=0; primes.find(num*num + a*num + *b) != primes.end(); num++) len++;
			if (len> max_len) {
				max_a = a;
				max_b = *b;
				max_len = len;
			}
			//std::cout << a << " " << *b << " : " << len << std::endl;
		}
	}

	return max_a*max_b;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
