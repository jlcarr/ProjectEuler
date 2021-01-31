// Solution to Project Euler problem 88

#include <iostream>
#include <chrono>


#include <set>
#include <map>
#include <vector>


/*
Interate through all multi-sets going up
As soon as the multiplier is greater than the addition stop
*/

void search(std::vector<int> multiset, int k, int sum_curr, int mul_curr, int target, std::map<int,int> &solutions){
	if(multiset.size() >= target) return;

	multiset.push_back(0);
	while(k < target){
		search(multiset, k, sum_curr, mul_curr, target, solutions);

		// Add to multiset
		multiset.back()++;
		k++;
		sum_curr += multiset.size()+1;
		mul_curr *= multiset.size()+1;
		if(mul_curr > 2*target) return;


		// report
		std::cout << "k = " << k << " ";
		for(auto i = 0; i < multiset.size(); i++) std::cout << "(" << i+2 << ":" << multiset[i] << ") "; 
		std::cout << "sum: " << sum_curr << " = " << " mul: " << mul_curr << std::endl;
		std::cout << std::endl;

		// Check for solution
		if(mul_curr <= sum_curr + (target - k)){
			int k_curr = k + (mul_curr - sum_curr);
			if(k_curr < 2) continue;
			if(solutions.find(k_curr) == solutions.end() || solutions[k_curr] > mul_curr) solutions[k_curr] = mul_curr;

		std::cout << "SOLUTION" << std::endl;
		std::cout << "k_curr = " << k_curr << " ";
		for(auto i = 0; i < multiset.size(); i++) std::cout << "(" << i+2 << ":" << multiset[i] << ") "; 
		std::cout << "sum: " << sum_curr << " = " << " mul: " << mul_curr << std::endl;
		std::cout << std::endl;

		}
		else return;
	}
}


int solution(){
	int target = 100;

	std::vector<int> multiset;
	int k = 0;
	int sum_curr = 0, mul_curr = 1;
	std::map<int,int> solutions;
	search(multiset, k, sum_curr, mul_curr, target, solutions);

	
	std::set<int> final_set;
	for(auto it = solutions.begin(); it != solutions.end(); it++) final_set.insert(it->second);
	int result = 0;
	for(auto it = final_set.begin(); it != final_set.end(); it++) result += *it;

	std::cout << "Finaly result: " << std::endl;
	for(auto it = solutions.begin(); it != solutions.end(); it++) std::cout << it->first << " : " << it->second << std::endl;
	std::cout << std::endl;

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
