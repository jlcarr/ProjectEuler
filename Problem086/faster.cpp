// Solution to Project Euler problem 86

#include <iostream>
#include <chrono>

#include <map>
#include <math.h>

/*
a>b>c

a^2 + (b+c)^2 = k^2


The fast method uses the below:
Euclid's method of generating Pythagorean triples
a = m^2 - n^2
b = 2*m*n
c = m^2 + n^2

*/


long solution(){
	long target = 1000*1000;
	
	long count = 0;
	long M = 0;
	while(count < target){
		M++;
		for(long b = 1; b <= M; b++){
			for(long c = 1; c <= b; c++){
				long k = (long) sqrt(M*M + (b+c)*(b+c));
				if(k*k == M*M + (b+c)*(b+c)){
					count++;
					//std::cout << "(" << M << "," << b << "," << c << ") count: " << count << std::endl;
				}
			}
		}
	}

/*
	int L_max = 1500000;
	//int L_max = 200;
	std::map<int,int> L_counts;

	for(int m=1; m*m < L_max; m++){
		for(int n=1; n < m && 2*m*m+2*m*n <= L_max; n++){
			// not both odd
			if(n%2 && m%2) continue;
			// coprime
			int gcd = m;
			int extra = n;
			while (extra){
				int temp = extra;
				extra = gcd % extra;
				gcd = temp;
			}
			if(gcd > 1) continue;
			// generate congruent triangles
			for(int k=1; 2*k*m*m+2*k*m*n <= L_max; k++){
				int a = k*(m*m - n*n);
				int b = k*(2*m*n);
				int c = k*(m*m + n*n);
				int L = a+b+c;
				L_counts[L]++;
				//std::cout << L << " cm: (" << a << ", " << b << ", " << c << ")" << std::endl;
			}
		}
	}

	int result = 0;
	for(auto it = L_counts.begin(); it != L_counts.end(); it++){
		if(it->second == 1) result++;
		//std::cout << it->first << " : " << it->second << std::endl;
	}
*/
	return M;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
