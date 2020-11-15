// Solution to Project Euler problem 63

#include <iostream>
#include <chrono>


#include <math.h>

/*
This problem can be solved by writing out the equation and simplifying by logs
10^n > b^n >= 10^(n-1)
n > n*log10(b) >= n-1
0 > n*(log10(b)-1) >= -1
1 >= n*(1-log10(b)) > 0

we can conclude
b=1 is the trivial solution
we need to check n for
9 >= b >= 2
floor(1/(1-log10(9))) >= n > floor(1/(1-log10(2)))
21 >= n >= 1

*/


int solution(){
	int result = 1;

	for(int i_n=1; i_n <= 21; i_n++){
		for(int i_b=2; i_b <=9; i_b++){
			double n = (double)i_n;
			double b = (double)i_b;
			double logval = n*(1.0-log10(b));
			if(1.0 >= logval && logval > 0) result++;
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
