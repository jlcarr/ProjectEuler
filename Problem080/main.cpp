// Solution to Project Euler problem 80

#include <iostream>
#include <chrono>


#include <gmpxx.h>
#include <string>
#include <math.h>

/*
Using the GNU multi-precision library we can simplify our lives a lot.

compile this one with:
g++ -std=c++0x main.cpp -lgmpxx -lgmp
*/


int solution(){
	mpz_class googol;
	mpz_ui_pow_ui(googol.get_mpz_t(), 10, 100);
	
	mpz_class digiter;
	mpz_pow_ui(digiter.get_mpz_t(), googol.get_mpz_t(), 2);


	int result = 0;
	for(int n = 1; n < 100; n++){
		if(((int)sqrt(n)) * ((int)sqrt(n)) == n) continue;
		mpz_class val = n;	

		mpz_class temp_result = sqrt(val * digiter);
		std::string digit_list = temp_result.get_str();

		for(int i=0; i<100; i++)
			result += digit_list[i] - '0';
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
