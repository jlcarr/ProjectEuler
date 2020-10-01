// Solution to Project Euler problem 24

#include <iostream>
#include <chrono>

#include <set>

/*
Super efficient solution (almost closed-form) using factorial number system
*/

long solution(){
	int target = 1000000-1;
	long result = 0;
	std::set<int> digits = {0,1,2,3,4,5,6,7,8,9};
	while (!digits.empty()){
		int factorial = 1;
		for(int i=0; i<digits.size()-1; i++) factorial *= i+1;
		
		int fac_dig = target / factorial;
		target -= fac_dig * factorial;
		//std::cout << "fact: " << factorial << " fac_dig: " << fac_dig << " target: " << target << std::endl;

		int dig = *std::next(digits.begin(), fac_dig);
		digits.erase(dig);
		result *= 10;
		result += (long) dig;
		//std::cout << "result: " << result << " dig: " << dig << " digits.size: " << digits.size() << std::endl;
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
