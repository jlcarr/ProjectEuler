// Solution to Project Euler problem 2

#include <iostream>
#include <chrono>

/*
Analytical solution:
Use the Binet formula to compute the Fibonacci numbers given n
sub 2*n+1 because even only occur every 3 terms
Sum the geometric series
*/

int solution(){
	int F1 = 1;
	int F2 = 1;
	int F3 = 2;
	int sum = 0;
	while (F3<4000000){
		sum += F3;
		F1 = F3+F2;
		F2 = F1+F3;
		F3 = F1+F2;
	}
	return sum;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
