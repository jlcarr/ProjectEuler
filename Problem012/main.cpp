// Solution to Project Euler problem 12

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <unordered_map>

/*
Solution approach
1. While loop numbers
2. Keep list of n to factorization (array->map)
3. Keep list of prime
4. If not prime found (using p*p<=n) then is prime
5. else can copy other factor from factorization list
*/

long solution(){ 
	std::list<int> primes;
	std::vector<std::unordered_map<int,int>> factors;

	primes.push_back(2);
	primes.push_back(3);
	factors.push_back(std::unordered_map<int,int>({{2,1}}));
	factors.push_back(std::unordered_map<int,int>({{3,1}}));

	for (int num=4; true; num++){
		// Find prime factor
		bool prime_check = true;
		auto it_prime = primes.begin();
		for (; it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check){
			primes.push_back(num);
			factors.push_back(std::unordered_map<int,int>({{num,1}}));
		}
		else {
			factors.push_back(factors[num/(*(--it_prime))-2]);
			factors.back()[*it_prime]++;
		}
		// Do check
		int fac1 = num%2? num : num/2;
		int fac2 = num%2? (num-1)/2 : num-1;
		
		std::unordered_map<int,int> temp;
		temp.clear();
		for (auto it_factor = factors[fac1-2].begin(); it_factor != factors[fac1-2].end(); ++it_factor)
			temp[it_factor->first] += it_factor->second;
		for (auto it_factor = factors[fac2-2].begin(); it_factor != factors[fac2-2].end(); ++it_factor)
			temp[it_factor->first] += it_factor->second;
		int n_factors = 1;
		for (auto it_factor = temp.begin(); it_factor != temp.end(); ++it_factor)
			n_factors *= 1+it_factor->second;
		//std::cout << num << " =>";
		//std::cout << fac1 << "*"<< fac2 << "=" << num*(num-1)/2 << " : ";
		//std::cout << n_factors << " = ";
		//for (auto z = factors[num-2].begin(); z != factors[num-2].end(); ++z) std::cout << z->first << ":" << z->second << ",";
		//std::cout << std::endl;
		if (n_factors > 500){
			int result = 1;
			for (auto it_factor = temp.begin(); it_factor != temp.end(); ++it_factor)
				for(int i = 0; i < it_factor->second; i++) result *= it_factor->first;
			return result;
		}
	}
	return -1;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
