// Solution to Project Euler problem 88

#include <iostream>
#include <chrono>


#include <set>
#include <map>
#include <vector>


/*
Factor all numbers in all ways up to 2*k_max
upper bound comes from
2 + k + sum_{1 -> k-2} = 2k
which has k terms and product = sum
*/

void search(int n, int max_factor, int n_curr, int sum_curr, int k_curr, std::map<int,int> &solutions){
	//std::cout << n << " -> " << n_curr << " : sum=" << sum_curr << " : k=" << k << " : max_factor=" << max_factor << std::endl;
	// If we've completed finding all the factors, check if the number is a valid solution
	if(n_curr == 1){
		int k = k_curr + (n - sum_curr);
		if(solutions.find(k) == solutions.end() || solutions[k] > n) solutions[k] = n;
		//std::cout << "n=" << n << " k=" << k << std::endl;
	}
	else {
		// Go through all factorizations, using the max_factor to ensure we don't double-count
		for(int factor = 2; factor <= max_factor; factor++){
			// if we have a factor continue our search
			if(n_curr % factor == 0) search(n, factor, n_curr/factor, sum_curr + factor, k_curr+1, solutions);
		}
	}
}


int solution(){
	int target = 12000;
	std::map<int,int> solutions;
	for (int n = 2; n <= target*2; n++) search(n, n, n, 0, 0, solutions);
	//search(10, 10, 10, 0, 0, solutions);
	
	std::set<int> final_set;
	for(auto it = solutions.lower_bound(2); it != solutions.end() && it->first <= target; it++) final_set.insert(it->second);
	int result = 0;
	for(auto it = final_set.begin(); it != final_set.end(); it++) result += *it;

	//std::cout << "Finaly result: " << std::endl;
	//for(auto it = solutions.lower_bound(2); it != solutions.end() && it->first <= target; it++) std::cout << it->first << " : " << it->second << std::endl;
	//std::cout << std::endl;

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
