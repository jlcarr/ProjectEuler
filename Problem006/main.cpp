// Solution to Project Euler problem 6

#include <iostream>
#include <chrono>

/*
There are closed-form solutions to sums of fixed powers
*/

long solution(){
	long n = 100;
	return (n*(n+1)/2)*(n*(n+1)/2) - n*(n+1)*(2*n+1)/6;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
