// Solution to Project Euler problem 3

#include <iostream>
#include <chrono>


int solution(){
	long x = 600851475143;
	long divisor;
	for (divisor=2 ; x>1; divisor++){
		while (!(x%divisor)) x /= divisor;
	}
	divisor--;
	return divisor;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
