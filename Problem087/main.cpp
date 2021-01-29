// Solution to Project Euler problem 87

#include <iostream>
#include <chrono>


#include <set>
#include <map>
#include <vector>


/*
Brute force
*/


long solution(){
	long target = 50*1000*1000;
	std::set<long> found = {2*2 + 2*2*2 + 2*2*2*2};
	std::set<long> primes = {2};

	// Gen primes needed
	int n = 3;
	for(int n=3; n*n < target; n+=2){
		// Check if next prime
		bool prime_check = true;
		for (auto it_prime = primes.begin(); it_prime != primes.end() && prime_check && (*it_prime)*(*it_prime) <= n; it_prime++)
			prime_check = n % *it_prime;
		if (prime_check) primes.insert(n);
	}

	for(auto a = primes.begin(); a != primes.end() && (*a)*(*a) < target; a++){
		for(auto b = primes.begin(); b != primes.end() && (*a)*(*a) + (*b)*(*b)*(*b) < target; b++){
			for(auto c = primes.begin(); c != primes.end() && (*a)*(*a) + (*b)*(*b)*(*b) + (*c)*(*c)*(*c)*(*c) < target; c++){
				found.insert( (*a)*(*a) + (*b)*(*b)*(*b) + (*c)*(*c)*(*c)*(*c) );
			}
		}
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
	return (long) found.size();
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
