// Solution to Project Euler problem 38

#include <iostream>
#include <chrono>

#include <set>
#include <vector>
#include <math.h>

/*
generate all permutations
loop initial digit groupings
check for subsequent doubling and tripling, and total validity
*/


long build_sol(std::vector<long> perm, std::set<long> digits){
	long perm_val = 0;
	for(auto perm_it = perm.begin(); perm_it != perm.end(); perm_it++) perm_val = 10*perm_val + *perm_it;

	//std::cout << "perm: " << perm_val <<std::endl;

	if (digits.empty()){
		//std::cout << "perm: " << perm_val <<std::endl;
		for(int i_cap=1; i_cap <= perm.size()/2; i_cap++){
			long b = 0;
			for(int i = 0; i < i_cap; i++) b = 10*b + perm[i];			
			//std::cout << "b = " << b << std::endl;

			bool is_sol = true;
			int index = i_cap;
			long n = 2;
			while(is_sol && index < perm.size()){
				long next = n*b;
				int len = (int)log10(next);
				//std::cout << "checking for " << next << " at " << index << " to " << len << std::endl;
				while(next && is_sol){
					//if(index+len < perm.size()) std::cout << "next= " << next << " perm= " << perm[index+len] << std::endl;
					is_sol = (index+len < perm.size() && perm[index+len] == next%10);
					next /= 10;
					len--;
				}
				index += 1+(int)log10(n*b);
				n++;
			}
			//std::cout << "is_sol = " << is_sol << " index = " << index << " permsize = " << perm.size() << std::endl;
			if(is_sol && index == perm.size()){
				//std::cout << "valid = " << perm_val << std::endl;
				return perm_val;
			}
		}
		return 0;
	}

	long result = 0;
	for(auto dig = digits.begin(); dig != digits.end(); dig++){
		std::set<long> temp_digits = digits;
		temp_digits.erase(*dig);
		perm.push_back(*dig);
		long temp_result = build_sol(perm, temp_digits);
		result = result > temp_result ? result : temp_result;
		perm.pop_back();
	}

	return result;
}


long solution(){
	std::set<long> digits = {1,2,3,4,5,6,7,8,9};
	std::vector<long> perm;

	return build_sol(perm, digits);
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
