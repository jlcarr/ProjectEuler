// Solution to Project Euler problem 95

#include <iostream>
#include <chrono>


#include <set>
#include <map>
#include <vector>
#include <list>


/*
Compute abundancies below 1milli
Count up finding chains, mapping values to lowest in their chain (and -1 if goes above 1-milli)
Keep track of chain length of shortest element 

Comput abundancy similar to problem 21
prime factor found = p
num = p*x = p^r *y
facsum(num) = (p^r + p^(r-1)+...+1)*facsum(y)
facsum(x) = (p^(r-1)+...+1)*facsum(y)
facsum(num) = p*facsum(x)+facsum(y) iff r>1
(p^(r+1)-1)/(p-1)
*/


int solution(){
	const int target = 1000*1000;
	std::vector<int> abundancy(target);
	std::map<int,int> chain_min;

	std::set<int> primes = {2};
	
	abundancy[1-1] = 1;
	abundancy[2-1] = 3;

	for(int n=3; n<=target; n++){
		bool prime_check = true;
		auto it_prime = primes.begin();
		for (; it_prime!=primes.end() && prime_check && (*it_prime)*(*it_prime)<=n; ++it_prime)
			prime_check = n % (*it_prime);
		if(prime_check){
			primes.insert(n);
			abundancy[n-1] = n+1;
		}
		else{
			// start with the prime factor
			it_prime--;
			int factor = *it_prime;
			// Use power factor so hold p^(r+1), and sub_factor to help compute it
			int sub_factor = n;
			int power_factor = factor;
			while (sub_factor%factor == 0){
				power_factor *= factor;
				sub_factor /= factor;
			}
			// We have successfully computer our abundancy in at most logarithmic time.
			abundancy[n-1] = (power_factor-1)/(factor-1) * abundancy[sub_factor-1];
		}
		//std::cout << n << " : " << abundancy[n-1] << std::endl;
	}

	chain_min[0] = -1;
	chain_min[1] = -1;
	int max_len = 0;
	int result = 0;

	for(int n=2; n<=target; n++){
		if(chain_min.find(n) != chain_min.end()) continue;

		std::set<int> chain = {n};
		std::list<int> chain_list = {n};
		int next = abundancy[n-1] - n;
		while(chain.find(next) == chain.end() && chain_min.find(next) == chain_min.end() && next <= target){
			chain.insert(next);
			chain_list.push_back(next);
			next = abundancy[next-1] - next;
		}
		//std::cout << std::endl;
		// If next > target need to set all in chain to -1
		// If if met chain_min, also set all in chain to -1
		// otherwise need to pop back until chain link is found. All others are duds

		int chain_len = -1;
		if(chain.find(next) != chain.end()){
			int min_val = next;
			for(auto it=chain_list.rbegin(); *it!=next; it++) if(*it < min_val) min_val = *it;
			auto it = chain_list.rbegin();
			for(; *it!=next; it++) chain_min[*it] = min_val;
			chain_min[next] = min_val;
			it++;
			for(; it!=chain_list.rend(); it++) chain_min[*it] = -1;

			chain_len = 1;
			for(it=chain_list.rbegin(); *it!=next; it++) chain_len++;
			if(chain_len > max_len){
				result = min_val;
				max_len = chain_len;
			}
		}
		else{
			for(auto it=chain.begin(); it!=chain.end(); it++)
				chain_min[*it] = -1;
		}
		//if(chain_len > 0) std::cout << n << " -> " << (abundancy[n-1]-n) << " -> " << chain_min[n] << " : " << chain_len << std::endl;
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
