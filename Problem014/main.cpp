// Solution to Project Euler problem 13

#include <iostream>
#include <chrono>

#include <map>


int collatz(long n, std::map<long,int> *chain_length){
	//std::cout << n << ",";
	if (chain_length->count(n) < 1) (*chain_length)[n] = 1+ ((n%2) ? collatz(3*n+1, chain_length) : collatz(n/2, chain_length));
	return (*chain_length)[n];	
}

long solution(){ 
	std::map<long,int> chain_length;
	chain_length[1] = 1;

	long result = 1;
	for (long i=1; i<1000000; i++) {
		//std::cout << "checking" << i << " : ";
		if (collatz(i, &chain_length) > chain_length[result]) result = i;
		//std::cout << " = " << chain_length[i] << std::endl;
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
