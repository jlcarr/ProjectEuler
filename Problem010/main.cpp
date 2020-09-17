// Solution to Project Euler problem 10

#include <iostream>
#include <chrono>

#include <list>

long solution(){ 
	std::list<int> primes;
	primes.push_back(2);
	for (int num=3; num<2000000; num+=2){
		bool prime_check = true;
		for (auto it_prime=primes.begin(); it_prime!=primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes.push_back(num);
	}
	long sum = 0;
	for (auto it_prime=primes.begin(); it_prime!=primes.end(); ++it_prime) sum += (long)*it_prime;
	return sum;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
