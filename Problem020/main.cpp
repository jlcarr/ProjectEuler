// Solution to Project Euler problem 20

#include <iostream>
#include <chrono>

#include <math.h>

// This is just a long number

int solution(){
	int len = 2*100;
	int digits[len];
	digits[0] = 1;
	for (int i=1; i<len; i++) digits[i] = 0;

	for (int i=1; i<=100; i++){
		for (int j=0; j<len; j++) digits[j] *= i;
		for (int j=0; j<len-1; j++){
			digits[j+1] +=  digits[j]/10;
			digits[j] %= 10;
		}
	}

	int result = 0;
	for (int i=0; i<len; i++) result += digits[i];

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
