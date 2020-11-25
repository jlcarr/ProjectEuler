// Solution to Project Euler problem 72

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <map>
#include <set>

/*
Solution approach
Use totient!

*/


long solution(){ 
	int target = 1000*1000;
	//int target = 8;

	std::vector<int> totients;
	std::list<int> primes;

	// Init
	primes.push_back(2);
	totients.push_back(2-1);
	long result = 1;

	for (int n=3; n <= target; n++){
		// Find prime factor
		bool prime_check = true;
		auto it_prime = primes.begin();
		for (; it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= n; ++it_prime) 
			prime_check = n % *it_prime;
		if (prime_check){
			primes.push_back(n);
			totients.push_back(n-1);
		}
		else {
			// If isn't prime, add sub-solution with the factor in
			it_prime--;
			int factor = *it_prime;
			
			int sub_n = n/factor;
			int sub_totient = totients[sub_n-2];
			if(sub_n%factor) totients.push_back(sub_totient*(factor-1));
			else totients.push_back(sub_totient*factor);
		}	

		result += (long) totients.back();
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
