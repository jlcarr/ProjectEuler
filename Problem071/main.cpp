// Solution to Project Euler problem 71

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <map>
#include <set>

/*
Solution approach
search over denominators d
find numerator via int division
check greater than
n_max/d_max > n/d ?
n_max*d > n*d_max ?

use long long cuz need > 10^12

*/


long long solution(){ 
	long long n_target = 3;
	long long d_target = 7;

	long long d_max = 1000*1000;
	//long long d_max = 8;

	long long n_result = -1;
	long long d_result = 1;

	for(long long d = 2; d <= d_max; d++){
		if (d % d_target == 0) continue;
		long long n_test = d*n_target/d_target;
		if (n_result*d < n_test*d_result) {
			n_result = n_test;
			d_result = d;
		}
	}
	//std::cout << n_result << "/" << d_result << std::endl;

	return n_result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
