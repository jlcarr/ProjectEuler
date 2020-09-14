// Solution to Project Euler problem 7

#include <iostream>
#include <chrono>

#include <list>

int solution(){ 
	std::list<int> primes;
	primes.push_back(2);
	for (int num=3; primes.size()<10001; num+=2){
		bool prime_check = true;
		for (auto it_prime=primes.begin(); it_prime!=primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes.push_back(num);
	}
	return primes.back();
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
