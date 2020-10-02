// Solution to Project Euler problem 25

#include <iostream>
#include <chrono>

#include <math.h>

/*
closed-form solution via the Binet formula
1000 = 1 + log10(phi^n / sqrt(5))
1000 = 1 + n*log10(phi) - log10(5)/2
*/

int solution(){
	double phi = (1.+sqrt(5.))/2.;
	return (int) ((1000. - 1. + log10(5.)/2.) / log10(phi)) + 1;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
