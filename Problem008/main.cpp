// Solution to Project Euler problem 8

#include <iostream>
#include <chrono>

long solution(){ 
	long digits[1000];
	FILE* fp = fopen("number.txt","r");
	for (int i=0; i<1000; i++) fscanf(fp, "%1ld", &digits[i]);
	fclose(fp);
	long max_mul = 0;
	for (int i=0; i<1000-13; i++) {
		long mul = 1;
		for (int k=0; k<13; k++) mul *= digits[i+k];
		if (mul>max_mul) max_mul = mul;
	}
	return max_mul;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
