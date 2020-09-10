// Solution to Project Euler problem 1

#include <iostream>

/*
Analytical solution:
int n_multplies_of_3 = (n-1)/3;
int n_multplies_of_5 = (n-1)/5;
int n_multplies_of_3_times_5 = (n-1)/3/5;

int sum_of_multiples_of_3 = n_multplies_of_3*(n_multplies_of_3+1)/2;
int sum_of_multiples_of_5 = n_multplies_of_5*(n_multplies_of_5+1)/2;
int sum_of_multiples_of_15 = n_multplies_of_15*(n_multplies_of_15+1)/2;

int solution = sum_of_multiples_of_3 + sum_of_multiples_of_5 - sum_of_multiples_of_15;

This can be generalized by taking combinations from a list of multiples
*/

int solution(){
	int n = 1000;
	int sum = 0;
	for (int i=0; i<n;i++) if(!(i%3) || !(i%5)) sum += i;
	return sum;
}

int main(){
	std::cout << solution() << std::endl;
	return 0;
}
