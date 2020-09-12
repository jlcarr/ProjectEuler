// Solution to Project Euler problem 4

#include <iostream>
#include <chrono>

bool is_palindrome(int x){
	int digits[6];
	for(int dig=0; dig<6; dig++, x/=10) digits[dig] = x%10;
	if (!digits[5]) return false;
	for (int dig=0; dig<3; dig++) if (digits[dig] != digits[5-dig]) return false;
	return true;
}

int solution(){
	int result;
	for(int i=999; i>99; i--){
		for(int j=0; j<=999-i; j++){
			int div1 = 999 - j;
			int div2 = i + j;
			result = div1*div2;
			if (is_palindrome(result)) return(result);
		}
	}
	return -1;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
