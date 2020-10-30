// Solution to Project Euler problem 47

#include <iostream>
#include <chrono>

#include <math.h>
#include <set>

/*
Solution approach
gen primes
while checking, if composite find # factors
if candidate keep track, if not reset candidate
*/

int solution(){
	int target = 4;
	int result = 0;
	int found = 0;

	std::set<int> primes = {2};
	int num = 2;

	while(true){
		num++;

		// Find prime factors
		int factor_count = 0;
		int temp = num;
		for (auto it_prime = primes.begin(); it_prime != primes.end() && (*it_prime)*(*it_prime) <= temp; ++it_prime){ 
			if(num % *it_prime == 0){
				//std::cout << "fact = " << *it_prime << std::endl;
				factor_count++;
				while(temp % *it_prime == 0) temp /= *it_prime;
			}
		}
		if(temp > 1){ 
			//std::cout << "fact = " << temp << std::endl;
			factor_count++;
		}
		//std::cout << "num = " << num << " factos = " << factor_count << std::endl;
		if (factor_count == target){
			if (!result) result = num;
			found++;
			if (found == target) return result;
		}
		else {
			if (temp == num) primes.insert(num);
			found = 0;
			result = 0;
		}
	}
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
