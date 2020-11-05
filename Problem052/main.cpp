// Solution to Project Euler problem 52

#include <iostream>
#include <chrono>

#include <map>
#include <math.h>

/* 
always start with 1
count up all lower
push digits into a map of digits to count
check equality for all multiples

simple search works fine.
The fact that the solution is the same as the digit expansion of 7 means something...
*/

std::map<int,int> dig_count(int n){
	std::map<int,int> result;
	int len = 1 + (int)log10(n);
	for(int i=0; i<len; i++){
		result[n%10]++;
		n/=10;
	}
	return result;
}

int solution(){
	int target = 6;
	std::map<int,int> dig_counts;
	std::map<int,int> temp_digs;

	int result = 1;
	while(true){
		dig_counts = dig_count(result);
		bool is_sol = true;
		for(int i=2; i<=target && is_sol; i++) is_sol = (dig_counts == dig_count(result*i));
		if(is_sol) return result;
		result ++;
	}

	return -1;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
