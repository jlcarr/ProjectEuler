// Solution to Project Euler problem 85

#include <iostream>
#include <chrono>


/*
Based upon the search size, should be on the order of 1000,000 operations

*/

long solution(){
	long target = 2*2 * 2*1000*1000;
	//long target = 2*2 * 17;
	long dist = target;
	long result = 0;

	long a = 0;
	do {
		a++;
		int b = 0;
		do {
			b++;
			if(abs(target - a*(a+1)*b*(b+1)) < dist){
				result = a*b;
				dist = abs(target - a*(a+1)*b*(b+1));
				//std::cout << "(" << a << "," << b << ") -> " << dist << std::endl;
			}
		} while(a*(a+1)*b*(b+1) <= target);
	} while(a*(a+1) <= target);

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
