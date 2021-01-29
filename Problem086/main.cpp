// Solution to Project Euler problem 86

#include <iostream>
#include <chrono>

#include <map>
#include <math.h>

/*
a>b>c

a^2 + (b+c)^2 = k^2

This is brute-forceable
Faster method is to use Euclid's prime generating


*/


long solution(){
	long target = 1000*1000;
	
	long count = 0;
	long M = 0;
	while(count < target){
		M++;
		for(long b = 1; b <= M; b++){
			for(long c = 1; c <= b; c++){
				long k = (long) sqrt(M*M + (b+c)*(b+c));
				if(k*k == M*M + (b+c)*(b+c)){
					count++;
					//std::cout << "(" << M << "," << b << "," << c << ") count: " << count << std::endl;
				}
			}
		}
	}

	return M;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
