// Solution to Project Euler problem 70

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <map>
#include <set>

/*
Solution approach
Copy problem 69 approach, except extra check

*/


int solution(){ 
	int target = 10*1000*1000;

	std::vector<int> totients;
	std::list<int> primes;

	// Init
	primes.push_back(2);
	totients.push_back(2-1);

	int result = -1;
	double min_ratio = 0;

	for (int n=3; n < target; n++){
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

		// Check is_perm
		std::vector<int> n_digs(10,0);
		std::vector<int> totient_digs(10,0);

		for(int temp = n; temp>0; temp /= 10) n_digs[temp%10]++;
		for(int temp = totients.back(); temp>0; temp /= 10) totient_digs[temp%10]++;

		if(n_digs == totient_digs){
			//std::cout << "phi(" << n << ") = " << totients.back() << std::endl;
			double new_ratio = ((double) n)/((double) totients.back());
			if(new_ratio < min_ratio || result == -1) {
				min_ratio = new_ratio;
				result = n;
			}
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
