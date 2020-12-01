// Solution to Project Euler problem 77

#include <iostream>
#include <chrono>


#include <set>
#include <map>
#include <vector>


/*
Dynamic Programming

Use a full table to build the solution
One dimension of the table is primes represending subsolutions using that prime size or lower (allowing therefore no double-counting)
Other dimension of the table is the number n which is being summed to
Table values are number of ways to make the sum
*/


int solution(){
	int target = 5000;
	std::map<int,std::vector<int>> subcount = {
		{2, {1,0,1,0}},
		{3, {1,0,1,1}}
	};


	// Main DP loop
	int n = 3;
	while(*(subcount.rbegin()->second.rbegin()) - (subcount.rbegin()->second.size() == subcount.rbegin()->first) < target){
		n++;
		// Check if new prime
		bool prime_check = true;
		for (auto it_prime=subcount.begin(); it_prime!=subcount.end() && prime_check && (it_prime->first)*(it_prime->first) <= n; ++it_prime)
			prime_check = n % it_prime->first;
		if (prime_check){
			// Add to the table
			subcount[n] = subcount.rbegin()->second;
			for(int i=0; i+n < subcount[n].size(); i++) subcount[n][i+n] = subcount[n][i];
		}
		
		// Add up all sub_sols
		int last = 0;
		for(auto it = subcount.begin(); it != subcount.end(); it++){
			it->second.push_back(last + it->second[it->second.size() - it->first]);
			last = it->second.back();
		}
		//std::cout << *(subcount.rbegin()->second.rbegin()) << std::endl;
		//if(n>10) break;
	}

	/*
	std::cout << "# : ";
	for(int i=0; i < subcount.begin()->second.size(); i++) std::cout << i << ", ";
	 std::cout << std::endl;
	for(auto p = subcount.begin(); p != subcount.end(); p++){
		std::cout << p->first << " : ";
		for(auto it = p->second.begin(); it != p->second.end(); it++) std::cout << *it << ", ";
		std::cout << std::endl;
	}
	*/
	return n;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
