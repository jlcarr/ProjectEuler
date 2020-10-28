// Solution to Project Euler problem 45

#include <iostream>
#include <chrono>

#include <math.h>

/*
hex > pent > tri
search hex and test on pent and tri

*/


long compute_tri(long n){
	return n*(n+1)/2;
}

bool is_tri(long T){
	long i = (long) (-1.0 + sqrt(1.0 + 8.0 * T))/2.0;
	return T == compute_tri(i);
}

long compute_pent(long n){
	return n*(3*n-1)/2;
}

bool is_pent(long P){
	long i = (long) (1.0 + sqrt(1.0 + 24.0 * P))/6.0;
	return P == compute_pent(i);
}

long compute_hex(long n){
	return n*(2*n-1);
}

bool is_hex(long H){
	long i = (long) (1.0 + sqrt(1.0 + 8.0 * H))/4.0;
	return H == compute_hex(i);
}


long solution(){
	long i = (long) (1.0 + sqrt(1.0 + 8.0 * 40755.0))/4.0;
	
	while(true){
		i++;
		long i_hex = compute_hex(i);
		//std::cout << "i = " << i << " hex = " << i_hex << std::endl;
		if(is_pent(i_hex) && is_tri(i_hex)) return i_hex;
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
