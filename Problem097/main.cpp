// Solution to Project Euler problem 97

#include <iostream>
#include <chrono>


/*
This is just modular arithmetic
Do fast exponentiation

*/

long long long_exp(long long b, long long exp, long long mod){
	if(!exp) return 1;
	long long result = long_exp(b, exp/2, mod);
	// avoid overflow with a hack
	bool hack = (mod /b/b/b/b < result);
	if (hack) result /= b*b*b*b;

	result *= result;
	result %= mod;

	// clean up after the hack
	if (hack) result *= b*b*b*b * b*b*b*b;
	result %= mod;

	if(exp%2){
		result *= b;
		result %= mod;
	}
	//std::cout << b << " ^ " << exp << " % " << mod << " = " << result << std::endl;
	return result;
}


long long solution(){
	long long result;
	long long mod = 1000LL*1000LL*1000LL*10LL;
	
	//for(long long i=0; i<20; i++) std::cout << i << ": " << long_exp(2, i, mod) << std::endl;
	result = long_exp(2, 10, 1000) +1LL;
	result = 28433LL*long_exp(2, 7830457LL, mod) +1LL ;
	result %= mod;	

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
