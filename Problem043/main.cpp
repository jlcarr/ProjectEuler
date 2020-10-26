// Solution to Project Euler problem 43

#include <iostream>
#include <chrono>

#include <set>
#include <vector>
#include <map>
#include <math.h>

/*
generate all permutations
while generating perform the checks
*/


std::map<long,long> conds = {{4,2},{5,3},{6,5},{7,7},{8,11},{9,13},{10,17}};

long gen_perms(std::vector<long> perm, std::set<long> digits){
	long perm_val = 0;
	for(auto perm_it = perm.begin(); perm_it != perm.end(); perm_it++) perm_val = 10*perm_val + *perm_it;
	//std::cout << "perm: " << perm_val <<std::endl;

	// check conds
	if(conds.find(perm.size()) != conds.end()){
		long substring = 0;
		for(int i=3; i>0; i--) substring = 10*substring + perm[perm.size()-i];
		//std::cout << "substring: " << substring << " perm: " << perm_val << std::endl;
		//std::cout << "perm_size: " << perm.size() << " cond: " << conds[perm.size()] << std::endl;
		if (substring%conds[perm.size()]) return 0;
	}

	if (digits.empty()){
		//std::cout << "sol: " << perm_val <<std::endl;
		return perm_val;
	}

	long result = 0;

	// gen new perms
	std::set<long> temp_digits = digits;
	for(auto dig = digits.begin(); dig != digits.end(); dig++){
		temp_digits.erase(*dig);
		perm.push_back(*dig);
		result += gen_perms(perm, temp_digits);
		perm.pop_back();
		temp_digits.insert(*dig);
	}

	return result;
}


long solution(){
	std::set<long> digits = {0,1,2,3,4,5,6,7,8,9};
	std::vector<long> perm;

	return gen_perms(perm, digits);
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
