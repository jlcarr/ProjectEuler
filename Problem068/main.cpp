// Solution to Project Euler problem 68

#include <iostream>
#include <chrono>

#include <set>
#include <vector>
#include <math.h>
#include <string>

/*
generate all permutations
while generating perform the checks
*/



long long gen_perms(int target, std::vector<int> inner, std::vector<int> outer, std::set<int> digits){
	// Check solution
	if(inner.size() == target && outer.size() == target){
		int sum = outer[0] + inner[0] + inner[1];
		bool is_sol = true;
		for(int i=0; i<target && is_sol; i++) is_sol = (sum == outer[i] + inner[i] + inner[(i+1)%target]);
		if(!is_sol) return 0;

		// Is solution, find index
		int min_i = 0, min_outer = 2*target;
		for(int i=0; i<target; i++) if(min_outer > outer[i]){
			min_i = i;
			min_outer = outer[i];
		}

		//for(int i=0; i<target; i++) std::cout << outer[i] << inner[i] << inner[(i+1)%target] << ";";
		//std::cout << " = " << sum << std::endl;
		//for(int i=0; i<target; i++) std::cout << outer[(i+min_i)%target] << "," << inner[(i+min_i)%target] << "," << inner[(i+min_i+1)%target] << ";";
		//std::cout << " = " << sum << std::endl;
		long long result = 0;
		//for(int i=0; i<target; i++) result = 1000*result + (long long) (100*outer[(i+min_i)%target] + 10*inner[(i+min_i)%target] + inner[(i+min_i+1)%target]);
		std::string temp_result;
		for(int i=0; i<target; i++) temp_result += std::to_string(outer[(i+min_i)%target]) + std::to_string(inner[(i+min_i)%target]) + std::to_string(inner[(i+min_i+1)%target]);
		result = stoll(temp_result, nullptr, 0);
		if(temp_result.length() != 16) return 0;
		//std::cout << temp_result << " = " << result << std::endl;
		return result;
	}

	// Partial checks
	if(outer.size() >= 1 && inner.size() >=2){
		int sum = outer[0] + inner[0] + inner[1];
		bool is_sol = true;
		for(int i=0; i < inner.size()-1 && i < outer.size() && is_sol; i++) is_sol = (sum == outer[i] + inner[i] + inner[(i+1)%target]);
		if(!is_sol) return 0;
	}

	// Generate next step of perms
	long long result = 0;
	for(auto it = digits.begin(); it != digits.end(); it++){
		std::set<int> digits_temp = digits;
		digits_temp.erase(*it);
		if(inner.size() < target && inner.size() <= outer.size()){
			inner.push_back(*it);
			long long temp = gen_perms(target, inner, outer, digits_temp);
			if(temp > result) result = temp;
			inner.pop_back();
		}
		else if(outer.size() < target){
			outer.push_back(*it);
			long long temp = gen_perms(target, inner, outer, digits_temp);
			if(temp > result) result = temp;
			outer.pop_back();
		}
	}

	return result;
}


long long solution(){
	std::set<int> digits = {1,2,3,4,5,6,7,8,9,10};
	int target = 5;
	//std::set<int> digits = {1,2,3,4,5,6};
	//int target = 3;

	return gen_perms(target, std::vector<int>(), std::vector<int>(), digits);
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
