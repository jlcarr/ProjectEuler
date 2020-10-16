// Solution to Project Euler problem 36

#include <iostream>
#include <chrono>

#include <list>

/* 
dirct approach
obtaining base digit string
*/


std::list<int> base_digit_string(int num, int base){
	std::list<int> result;
	while(num){
		int dig = num % base;
		num /= base;
		result.push_back(dig);
	}
	return result;
}

long solution(){ 
	int n = 1000000;

	int result = 0;
	for(int i=1; i<n; i+=2){
		bool is_palindrome = true;
		// decimal
		std::list<int> dig_string = base_digit_string(i, 10);
		auto dig = dig_string.begin();
		auto rdig = dig_string.rbegin(); 
		for(;dig != dig_string.end() && rdig != dig_string.rend() && is_palindrome;
			dig++,rdig++)
				is_palindrome = (*dig == *rdig);
		// binary
		dig_string = base_digit_string(i, 2);
		dig = dig_string.begin();
		rdig = dig_string.rbegin(); 
		for(;dig != dig_string.end() && rdig != dig_string.rend() && is_palindrome;
			dig++,rdig++)
				is_palindrome = (*dig == *rdig);
		if(is_palindrome){
			result += i;
			//std::cout << i << std::endl;
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
