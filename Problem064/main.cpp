// Solution to Project Euler problem 64

#include <iostream>
#include <chrono>


#include <math.h>
#include <vector>
#include <map>

/*
Get a-value
floor (n_k + z)/d_k = a_k
compute next fraction iteration
(z + n_k - a_k * d_k)/d_k 
= 1 / ( d_k * (z - n_k + a_k * d_k) / (z^2 - (n_k - a_k * d_k)^2))
therefore
n_(k+1) = z - n_k + a_k * d_k
d_(k+1) = (z^2 - (n_k - a_k * d_k)^2) / d_k

Now when we reach same n and d we know we've found the cycle
*/


int solution(){
	int target = 10000;
	int result = 0;

	for(int N = 2; N <= target; N++){
		int z = (int)sqrt(N);
		// forget perfect squares: just want irrationals
		if (z*z == N) continue;
		//std::cout << "N = " << N;
		// init tracker
		std::map<std::vector<int>,int> steps;
		// initialize numerator and denominator
		int step = 0;
		int n = 0;
		int d = 1;
		
		std::vector<int> key_pair = {n,d};
		do {
			steps[key_pair] = step++;
			// calculate next values
			int a = (z+n)/d;
			int n_next = a*d-n;
			d = (N - (n-a*d)*(n-a*d))/d;
			n = n_next;
			key_pair = {n,d};
			//std::cout << " (" << a << "," << n << "," << d << ")->";
		} while(steps.find(key_pair) == steps.end());
		int cycle_len = steps.size() - steps[key_pair];
		if(cycle_len%2) result++;
		//std::cout << " cycle: " << cycle_len << std::endl;
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
