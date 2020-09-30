// Solution to Project Euler problem 23

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <set>

/*
Solution approach
1. Generate list of abundancy<28123 and primes
2. Put abundant numbers in and ordered set
3. for all num<28123 check if any value in the set (<=num/2)has an sum pair
4. compute result

See Problem 21
*/


int solution(){ 
	int n = 28123;

	// Step 1. Abundancy list
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

	// Step 2: put all abundant number is an ordered set
	std::set<int> abundants;
	for(int i=0; i<n-1; i++) if(abundancy[i] > 2*i+2){
		abundants.insert(i+1);
		//std::cout << i+1 << " : " << abundancy[i] << std::endl;
	}

	// Step 3:
	int result = 0;
	for(int num=1; num<=n; num++){
		result += num;
		for(auto it=abundants.begin(); it!=abundants.end() && *it<=num/2; ++it){
			if(abundants.find(num - *it) != abundants.end()){
				//std::cout << num << " : " << *it << std::endl;
				result -= num;
				break;
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
