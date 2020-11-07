// Solution to Project Euler problem 55

#include <iostream>
#include <chrono>

#include <list>
#include <math.h>

/*
Solution approach
long addition
prep for palidrome addition

longest number will be on the order of 10000*2^50
~ 4 + 50/3 ~ 22 digits
operations to perform
10000*50*22 ~ 1000,000
*/

int solution(){
	int n = 10000;
	int result = 0;

	// Check each num
	for(int num = 1; num < n; num++){
		//std::cout << "n = " << num << std::endl;
		// convert to list
		std::list<int> digit_string;
		for(int temp=num; temp>0; temp/=10) digit_string.push_back(temp%10);
		
		bool is_palindrome = false;
		for(int test_count=0; test_count<50 && !is_palindrome; test_count++){
			// add palindromes
			int carry = 0;
			std::list<int> temp_digit_string;
			auto it_dig = digit_string.begin();
			auto it_rev = digit_string.rbegin();
			while(it_dig != digit_string.end() && it_rev != digit_string.rend()){
				temp_digit_string.push_back((*it_dig + *it_rev + carry)%10);
				carry = (*it_dig + *it_rev + carry)/10;
				it_dig++;
				it_rev++;
			}
			if(carry!=0) temp_digit_string.push_back(carry);
			digit_string = temp_digit_string;
			
			//for(it_rev = digit_string.rbegin(); it_rev != digit_string.rend(); it_rev++) std::cout << *it_rev;
			//std::cout << " -> ";

			// check if is palindrome
			it_dig = digit_string.begin();
			it_rev = digit_string.rbegin();
			is_palindrome = true;
			while(it_dig != digit_string.end() && it_rev != digit_string.rend() && is_palindrome){ 
				is_palindrome = (*it_dig == *it_rev);
				it_dig++;
				it_rev++;
			}
		}
		if(!is_palindrome) result++;
		//std::cout << std::endl;
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
