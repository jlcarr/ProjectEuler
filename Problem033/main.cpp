// Solution to Project Euler problem 33

#include <iostream>
#include <chrono>


/*
simple loop digs in [1-9]
(a1*10 + a0)/(b1*10 + b0) = ai/bj
bj*a1*10 + bj*a0 = ai*b1*10 + ai*b0

total of 9*9*9*9*2*2 = 26244

finish of euclid's for gcd, and divide through 
*/


int solution(){
	// Generate full fraction
	int numerator = 1;
	int denominator = 1;
	int a[2],b[2];
	for(a[1] = 1; a[1] <= 9; a[1]++){
		for(a[0] = 1; a[0] <= 9; a[0]++){
			for(b[1] = 1; b[1] <= 9; b[1]++){
				for(b[0] = 1; b[0] <= 9; b[0]++){
					if(a[1]*10+a[0] >= b[1]*10+b[0]) continue;
					for(int i=0; i<2; i++){
						for(int j=0; j<2; j++){
							if(a[1-i] != b[1-j]) continue;
							if(b[j]*a[1]*10 + b[j]*a[0] == a[i]*b[1]*10 + a[i]*b[0]){
								numerator *= a[i];
								denominator *= b[j];
								//std:: cout << a[1] << a[0] << " / " << b[1] << b[0] << " = " << a[i] << " / " <<  b[j] << std::endl;
								//std::cout << b[j]*a[1]*10 + b[j]*a[0]  << " == " << a[i]*b[1]*10 + a[i]*b[0] << std::endl;
								//std::cout << numerator << " / " << denominator << std::endl << std::endl;
							}
						}
					}
				}
			}
		}
	}

	//std::cout << numerator << " / " << denominator << std::endl;
	// Get gcd via euclid's
	int gcd = numerator;
	int extra = denominator;
	while (extra){
		int temp = extra;
		extra = gcd % extra;
		gcd = temp;
	}
	
	int result = denominator / gcd;
	
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
