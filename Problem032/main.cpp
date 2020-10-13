// Solution to Project Euler problem 32

#include <iostream>
#include <chrono>

#include <set>
#include <vector>

/*
generate all permutations
search for x and = placement, keeping number length in mind
*/


int build_sol(std::vector<int> perm, std::set<int> digits, std::set<int> *sols){
	//for(auto i = perm.begin(); i != perm.end(); i++) std::cout << *i;
	//std::cout << std::endl;

	int result = 0;
	if (digits.empty()){
		for(int i_cap=1; i_cap <= perm.size()/2; i_cap++){
			for(int j_cap=i_cap+1; j_cap <= 1+perm.size()/2; j_cap++){
				int l = 0;
				for(int i = 0; i < i_cap; i++) l = 10*l + perm[i];
				int r = 0;
				for(int j = i_cap; j < j_cap; j++) r = 10*r + perm[j];
				int lr = 0;
				for(int i = j_cap; i < perm.size(); i++) lr = 10*lr + perm[i];
				if(l*r == lr && sols->find(lr) == sols->end()){
					result += lr;
					//std::cout << l << " x " << r << " = " << lr << std::endl;
					sols->insert(lr);
				}
			}
		}
		return result;
	}

	for(auto dig = digits.begin(); dig != digits.end(); dig++){
		std::set<int> temp_digits = digits;
		temp_digits.erase(*dig);
		perm.push_back(*dig);
		result += build_sol(perm, temp_digits, sols);
		perm.pop_back();
	}

	return result;
}


int solution(){
	std::set<int> digits = {1,2,3,4,5,6,7,8,9};
	std::vector<int> perm;
	std::set<int> sols;


	//return check_partial(l, r, digits);
	return build_sol(perm, digits, &sols);
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
