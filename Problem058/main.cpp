// Solution to Project Euler problem 58

#include <iostream>
#include <chrono>


#include <set>

/*
loop up r=1
 
s = 2*r+1
DR = s^2
DL = s^2 - (s-1)
UL =  s^2 - 2*(s-1)
UR = s^2 - 3*(s-1)

sum prime count
sum base count
above 10%

*/

bool is_prime(int n, std::set<int> *primes){
	// check if in known primes
	if(primes->find(n) != primes->end()) return true;

	// check if factor known already
	bool prime_check = true;
	for (auto it_prime=primes->begin(); it_prime!=primes->end() &&  prime_check && (*it_prime)*(*it_prime) <= n; ++it_prime)
		prime_check = n % *it_prime;
	if(!prime_check) return false;

	// generate primes until have enough to check primality
	for (int num = *(primes->rbegin()); num*num <= n; num += 2){
		prime_check = n % num;
		if(!prime_check) return false;

		bool sub_prime_check = true;
		for (auto it_prime=primes->begin(); it_prime!=primes->end() && sub_prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime)
			sub_prime_check = num % *it_prime;
		if (sub_prime_check) primes->insert(num);
	}
	return true;
}


int solution(){
	std::set<int> primes = {2,3};

	int r = 1;
	int total_count = 1; //starts at 1
	int prime_count = 0; // 1 isn't a prime
	while(true){
		total_count += 4;
		int s = 2*r+1;
		// DR cannot be prime
		for(int i=1; i<4; i++) if(is_prime(s*s - i*(s-1), &primes)) prime_count++;
		//std::cout << "s = " << s << " count = " << prime_count << " / " << total_count << std::endl;
		if(10*prime_count/total_count < 1) return s;
		r++;
	}
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
