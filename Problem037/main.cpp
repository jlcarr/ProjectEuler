// Solution to Project Euler problem 37

#include <iostream>
#include <chrono>

#include <set>
#include <math.h>

/* 
use set for primes for faster searching
use sqrt for search
cache primes
*/


bool is_prime(long n, std::set<long> *primes){
	// check if in known primes
	if(primes->find(n) != primes->end()) return true;

	// check if factor known already
	bool result = true;
	for (auto it_prime=primes->begin(); it_prime!=primes->end() && result && (*it_prime)*(*it_prime) <= n; ++it_prime)
		result = n % *it_prime;
	if(!result) return false;

	// generate primes until have enough to check primality
	for (long num = *(primes->rbegin()); num*num <= n; num += 2){
		result = n % num;
		if(!result) break;

		bool prime_check = true;
		for (auto it_prime=primes->begin(); it_prime!=primes->end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes->insert(num);
	}
	return result;
}

std::set<long> extend_sol(long sol, std::set<long> *primes){
	//std::cout << "checking: " << sol << std::endl;
	int len = 1 + (int)log10(sol);
	if (len >6) return std::set<long>(); // How can we optimize to not need this?
	long cap = 1;
	for(int i=0; i<len; i++) cap *= 10;

	// explore extended solutions
	std::set<long> result;
	for(long i=1; i<=9; i++){
		long new_sol = i*cap + sol;
		if (!is_prime(new_sol,primes)) continue;
		std::set<long> temp = extend_sol(new_sol, primes);
		result.insert(temp.begin(),temp.end());
	}

	// check if is true solution
	long temp_sol = sol;
	bool is_sol = (sol%10 != 1) && (10*sol/cap != 1);
	while(temp_sol && is_sol){
		is_sol = is_prime(temp_sol,primes);
		temp_sol /= 10;
	}
	if(is_sol){
		result.insert(sol);
		//std::cout << "found: " << sol << std::endl;
	}

	return result;
}


long solution(){ 
	std::set<long> primes = {2,3,5,7};

	std::set<long> result_set;
	std::set<long> initial_primes = primes;
	for(auto p = initial_primes.begin(); p != initial_primes.end(); p++){
		std::set<long> temp = extend_sol(*p, &primes);
		result_set.insert(temp.begin(),temp.end());
	}
	//std::cout << "size: " << result_set.size() << std::endl;
	long result = 0;
	for(auto p = result_set.begin(); p != result_set.end(); p++) result += *p;
	for(auto p = initial_primes.begin(); p != initial_primes.end(); p++) result -= *p;
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
