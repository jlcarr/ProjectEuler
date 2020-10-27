// Solution to Project Euler problem 44

#include <iostream>
#include <chrono>

#include <math.h>

/*
P(i) + P(j) = P(s)
P(i) - P(j) = P(d)
min d

2*P(j) + P(d) = P(s)

The closer i and j are together the smaller d.
Therefore simple search

How to check Pentagonal
P(i) = i*(3*i-1)/2t 
0 = 3*i^2 - i - 2*P(i)
i = (1 +- sqrt(1 + 24*P(i))/6

*/


int compute_pent(int n){
	return n*(3*n-1)/2;
}

bool is_pent(int P){
	int i = (int) (1.0 + sqrt(1.0 + 24.0 * P))/6.0;
	return P == compute_pent(i);
}


int solution(){
	int i = 2;
	
	while(true){
		i++;
		int i_pent = compute_pent(i);
		for(int j=i-1; j>0; j--) {
			int j_pent = compute_pent(j);
			if(is_pent(i_pent + j_pent) && is_pent(i_pent-j_pent)) return i_pent-j_pent;
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
