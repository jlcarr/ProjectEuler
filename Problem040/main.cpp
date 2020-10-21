// Solution to Project Euler problem 40

#include <iostream>
#include <chrono>

#include <math.h>

/*
close to closed form
1-9 (9 x 1): 1-9
10-99 (90 x 2): 10-189
100-999 (900 x 3): 
= 9*(1*10^0+2*10^1+...)

easy way is just to loop to remove powers
*/


int champernowne_digit(int n){
	int digs = 1;
	int pos = 1;
	while(n > digs*9*pos){
		n -= digs*9*pos;
		pos *= 10;
		digs++;
	}
	int sub_pos = (n-1)%digs;
	int true_n = ((n-1)/digs) + pos;
	int result = true_n;
	for(int i=0; i<digs-sub_pos-1; i++) result /= 10;
	result %= 10;
	//std::cout << "true_n = " << true_n << " sub_pos = " << sub_pos << " result = " << result << std::endl;
	return result;
}


int solution(){
	int result = 1;
	int n = 1;
	
	for(int i=0; i<7; i++){
		result *= champernowne_digit(n);
		n *= 10;
	}
	
	/*for(int i=1; i<=20; i++){
		std::cout << "i = " << i << std::endl;
		champernowne_digit(i);
	}*/
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
