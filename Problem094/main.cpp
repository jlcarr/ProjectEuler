// Solution to Project Euler problem 94

#include <iostream>
#include <chrono>

#include <map>
#include <math.h>

/*
Dividing the isoceles triangle in half makes 2 right-angle triangles

c<=L_max
Euclid's method of generating Pythagorean triples
a = m^2 - n^2
b = 2*m*n
c = m^2 + n^2

*/


long solution(){
	//long L_max = 1000*1000*1000;
	long L_max = 1000*1000*1000;
	
	long result = 0;
	for(long m=1; m*m <= L_max; m++){
		for(long n=1; n < m && 2*m*m+2*m*n <= L_max; n++){
			// not both odd
			if(n%2 && m%2) continue;
			// coprime
			long gcd = m;
			long extra = n;
			while (extra){
				long temp = extra;
				extra = gcd % extra;
				gcd = temp;
			}
			if(gcd > 1) continue;
			// generate congruent triangles
			for(long k=1; 2*k*m*m+2*k*m*n <= L_max; k++){
				long a = k*(m*m - n*n);
				long b = k*(2*m*n);
				long c = k*(m*m + n*n);
				if(2*a-1 == c){
					result += 3*c+1;
					//std::cout << "+1 s = " << c << " A = " << a*b << std::endl;
				}
				if(2*a+1 == c){
					result += 3*c-1;
					//std::cout << "-1 s = " << c << " A = " << a*b << std::endl;
					
				}
				if(2*b-1 == c){
					result += 3*c+1;
					//std::cout << "+1 s = " << c << " A = " << a*b << std::endl;
				}
				if(2*b+1 == c){
					result += 3*c-1;
					//std::cout << "-1 s = " << c << " A = " << a*b << std::endl;
				}
				//std::cout << L << " cm: (" << a << ", " << b << ", " << c << ")" << std::endl;
			}
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
