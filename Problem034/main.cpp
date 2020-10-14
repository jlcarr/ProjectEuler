// Solution to Project Euler problem 34

#include <iostream>
#include <chrono>

#include <math.h>

/*
max n
n * 9! > 10^n - 1
9! = 362880
n = 7

loop numbers with digits in array
sum factorials and compare

*/


long solution(){
	int n = 7;
	long max_val = 1;
	for(int i=0; i<n; i++) max_val *= 10;

	long result = 0;
	for(long num = 3; num < max_val; num++){
		//check factorials
		long temp = num;
		long fac_sum = 0;
		for(int i=0; i < 1+(int)log10(num); i++){
			long dig = temp % 10;
			temp /= 10;

			//factorial
			long dig_fact = 1;
			for(long i=2; i<=dig; i++) dig_fact *= i;
			
			fac_sum += dig_fact;
		}
		if (fac_sum == num){
			//std::cout << num << std::endl;
			result += num;
		}
	}
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
