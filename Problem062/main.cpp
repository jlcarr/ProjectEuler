// Solution to Project Euler problem 62

#include <iostream>
#include <chrono>


#include <math.h>
#include <vector>
#include <map>

/*
simply enumerate cubes, 
get the counts of their digits, 
which maps to all perms
keep count
*/


long long solution(){
	int target = 5;
	std::map<std::vector<int>,int> digit_counts;
	std::map<std::vector<int>,long long> orig;

	long long num = 1;
	while(num < 100000){
		// Perform cube
		long long cube = num*num*num;
		//std::cout << cube << std::endl;
		// Get digit counts
		std::vector<int> digit_count(10,0);
		for(long long temp = cube; temp > 0; temp/=10) digit_count[(int)(temp%10)]++;
		digit_counts[digit_count]++;
		if(orig.find(digit_count) == orig.end()) orig[digit_count] = cube;
		if(digit_counts[digit_count] == target) return orig[digit_count];
		num++;
	}

	return 0;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
