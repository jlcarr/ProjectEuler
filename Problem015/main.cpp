// Solution to Project Euler problem 15

#include <iostream>
#include <chrono>

/*
Closed form solution via stars and bars
(20+20) choose (20)
Unfortenately C++ doesn't come with this function, and it's easy to overflow.
Used some cleverness to avoid this
*/

unsigned long long solution(){
	unsigned long long n = 1;
	for(unsigned long long k=0; k<10; k++) n *= 40-2*k-1;
	for(unsigned long long k=0; k<10; k++) n *= 2;
	for(unsigned long long k=0; k<10; k++) n /= 10-k;
	return n;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
