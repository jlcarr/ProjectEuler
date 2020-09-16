// Solution to Project Euler problem 9

#include <iostream>
#include <chrono>


int solution(){ 
	for (int a=1; a<=998; a++){
		for (int b=1; b<=a; b++){
			if(a*a + b*b == (1000-a-b)*(1000-a-b)) return a*b*(1000-a-b);
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
