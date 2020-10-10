// Solution to Project Euler problem 31

#include <iostream>
#include <chrono>

#include <list>

/*
Dynamic Programming

subproblem lookup table
simple loop

*/


int solution(){
	int target=200;
	std::list<int> coins = {1,2,5,10,20,50,100,200};
	int subcount[target+1];
	for(int i=0; i<=target; i++) subcount[i] = 0;
	subcount[0] = 1;
	
	// Main DP loop
	for(auto c = coins.begin(); c != coins.end(); c++)
		for(int i=0; i + *c <= target; i++)
			subcount[i + *c] += subcount[i];
	
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
