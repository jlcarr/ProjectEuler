// Solution to Project Euler problem 21

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <unordered_map>

/*
prime factor found = p
num = p*x = p^r *y
facsum(num) = (p^r + p^(r-1)+...+1)*facsum(y)
facsum(x) = (p^(r-1)+...+1)*facsum(y)
facsum(num) = p*facsum(x)+facsum(y) iff r>1
(p^(r+1)-1)/(p-1)
*/


int solution(){ 
	int n = 10000;
	int abundancy[n];

	std::list<int> primes;

	primes.push_back(2);
	abundancy[2-1] = 3;
	abundancy[1-1] = 1;

	for (int num=3; num < n; num++){
		// Find prime factor
		bool prime_check = true;
		auto it_prime = primes.begin();
		for (; it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check){
			primes.push_back(num);
			abundancy[num-1] = num+1;
		}
		else {
			it_prime--;
			// Determine (p^(r+1)-1)/(p-1)
			int factor = *it_prime;
			int sub_factor = num;
			int power_factor = factor;
			//std::cout << factor <<std::endl;
			while (!(sub_factor%factor)){
				power_factor *= factor;
				sub_factor /= factor;
			}
			abundancy[num-1] = (power_factor-1)/(factor-1)*abundancy[sub_factor-1];
		}
		//std::cout << num << " : " << abundancy[num-1]-num << std::endl;
	}
	int result = 0;
	for (int i=2; i<n; i++){
		int possible_pair = abundancy[i-1]-i;
		if (possible_pair < n && i != possible_pair && i == abundancy[possible_pair-1] - possible_pair){
			//std::cout << i << std::endl;
			result += i;
		}
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
