// Solution to Project Euler problem 48

#include <iostream>
#include <chrono>


/*
Solution approach
loop, use fast modular exponentiation, specially for this

actually just used simple exponentiation for simplicity
*/

unsigned long long solution(){
	int n = 1000;
	int len = 10;
	int digits[len];
	for (int i=0; i<len; i++) digits[i] = 0;

	for(int i = 1; i <= n; i++){
		int temp[len];
		temp[0] = 1;
		for (int j=1; j<len; j++) temp[j] = 0;

		int pow = i;
		while(pow){
			if(pow%2 || true){
				for (int j=0; j<len; j++) temp[j] *= i;
				for (int j=0; j<len-1; j++) temp[j+1] +=  temp[j]/10;
				for (int j=0; j<len; j++) temp[j] %= 10;
				pow--;
			}
		}
		//std::cout << "i = " << i << " temp = ";
		//for(int j=len-1; j>=0; j--) std::cout << temp[j];
		//std::cout << std::endl;
		//std::cout << "prefinal = ";
		//for(int j=len-1; j>=0; j--) std::cout << digits[j];
		//std::cout << std::endl;
		for (int j=0; j<len; j++) digits[j] += temp[j];
		for (int j=0; j<len-1; j++) digits[j+1] +=  digits[j]/10;
		for (int j=0; j<len; j++) digits[j] %= 10;
		//std::cout << "postfinal = ";
		//for(int j=len-1; j>=0; j--) std::cout << digits[j];
		//std::cout << std::endl;
	}

	//std::cout << "final = ";
	//for(int j=len-1; j>=0; j--) std::cout << digits[j];
	//std::cout << std::endl;

	unsigned long long result = 0;
	for (int j=len-1; j>=0; j--) result = 10*result + (unsigned long long)digits[j];
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
