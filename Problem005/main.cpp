// Solution to Project Euler problem 5

#include <iostream>
#include <chrono>

/*
Take the highest power less than 20 of each prime less than 20
This can be done programmatically, but it for fixed 20 we can do this by hand
*/

long solution(){
	return 16*9*5*7*11*13*17*19;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
