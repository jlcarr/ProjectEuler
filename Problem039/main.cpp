// Solution to Project Euler problem 39

#include <iostream>
#include <chrono>

#include <unordered_map>
#include <math.h>

/*
a+b+c=p<=1000
c>a>b
a+b>c
therefore c<500

so:
loop a<500
loop b<a
if solution, store p in map
check solution by sqrt, round, sqr
*/


int solution(){
	int n = 1000;
	std::unordered_map<int,int> p_counts;

	for(int a=1; a<n/2; a++){
		for(int b=1; b<=a; b++){
			int c = (int) round(sqrt(a*a + b*b));
			if (c*c == a*a + b*b) p_counts[a+b+c] += 1;
		}
	}

	int result = 0;
	int result_count = 0;
	for(auto it=p_counts.begin(); it != p_counts.end(); it++) {
		if(it->second > result_count){
			result = it->first;
			result_count = it->second;
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
