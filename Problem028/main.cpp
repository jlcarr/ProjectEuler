// Solution to Project Euler problem 28

#include <iostream>
#include <chrono>


/*
for i=0 <= n/2

width = 2*i+1
UR = width^2
UL = width^2-width+1
DL = width^2-2*width+2
DR = width^2-3*width+3
sum = 4*width^2-6*width+6
sum = 16*i^2+4*i+4

r = (int) n/2
solution = 16*r*(r+1)*(2*r+1)/6 + 4*r*(r+1)/2 + 4*r - 3

*/

long solution(){
	long n = 1001;
	long r = n/2;

	return 16*r*(r+1)*(2*r+1)/6 + 4*r*(r+1)/2 + 4*r +1;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
