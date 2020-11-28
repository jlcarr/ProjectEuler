// Solution to Project Euler problem 74

#include <iostream>
#include <chrono>

#include <vector>
#include <set>

/*
keep iterating, checking for if see before in chair
could increase performance by caching all previous loops with sizes

*/


int solution(){ 
	unsigned long long  target = 1000*1000;
	int result = 0;

	std::vector<unsigned long long> dig_fac(1,1);
	for(unsigned long long i = 1; i < 10; i++) dig_fac.push_back(dig_fac.back() * i);


	for(unsigned long long n = 0; n < target; n++){
		//std::cout << n << " = ";
		unsigned long long temp = n;
		std::set<unsigned long long> chain;
		while(chain.find(temp) == chain.end()){
			chain.insert(temp);
			unsigned long long sum = 0;
			for(; temp > 0; temp /= 10) sum += dig_fac[temp%10];
			temp = sum;
			//std::cout << temp << " -> ";
		}
		//std::cout << std::endl;
		if(chain.size() == 60) result++;
		//std::cout << n << " = " << chain.size() << std::endl;
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
