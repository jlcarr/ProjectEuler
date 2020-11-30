// Solution to Project Euler problem 76

#include <iostream>
#include <chrono>


/*
Dynamic Programming
Simple copy of Problem 31

*/


int solution(){
	int target = 100;
	int subcount[target+1];
	for(int i=0; i<=target; i++) subcount[i] = 0;
	subcount[0] = 1;
	
	// Main DP loop
	for(int n = 1; n < target; n++)
		for(int i=0; i + n <= target; i++)
			subcount[i + n] += subcount[i];
	
	//for(int i=0; i<=target; i++) std::cout << subcount[i] << std::endl;
	
	return subcount[target];
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
