// Solution to Project Euler problem 100

#include <iostream>
#include <chrono>


#include <math.h>
#include <gmpxx.h>
#include <string>

/*
B/(R+B) * (B-1)/(R+B-1) = 1/2
2*B^2 - 2*B = R^2 + 2*R*B + B^2 - R - B
0 = R^2 + 2*R*B - B^2 - R + B

Apply Quadratic equation for each

0 = R^2 + (2*B-1)*R + (-B^2+B)
0 = -B^2 + (2*R+1)*B + (R^2-R)

R = [-2*B+1 +- sqrt(4*B^2-4*B+1 + 4*B^2 - 4*B)]/2
R = [-2*B+1 +- sqrt(8*B^2 - 8*B + 1)]/2

B = [2*R+1 -+ sqrt(4*R^2+4*R+1 + 4*R^2 - 4*R)]/2
B = [2*R+1 -+ sqrt(8*R^2 + 1)]/2

We need the discriminant to be a square number. One of our cases therefore become's Pell's equation.

S^2 = 8*R^2 + 1
S^2 - 8*R^2 = 1


This is Pell's equation
There is a strong connection to continued fractions, hence it's placement here
x^2 - D * y^2 = 1
(x^2 - 1)/y^2 = D
sqrt(D) = sqrt(x^2-1)/y ~= x/y

Process from problem 64
z = floor sqrt(N)
n_0 = 0
d_0 = 1

a_k = floor (n_k + z)/d_k


Get a-value
floor (n_k + z)/d_k = a_k
compute next fraction iteration
(z + n_k - a_k * d_k)/d_k 
= 1 / ( d_k * (z - n_k + a_k * d_k) / (z^2 - (n_k - a_k * d_k)^2))
therefore
n_(k+1) = z - n_k + a_k * d_k
d_(k+1) = (z^2 - (n_k - a_k * d_k)^2) / d_k
 
Get next fraction from:
n_k = a_k * n_(k-1) + n_(k-2)
d_k = a_k * d_(k-1) + d_(k-2)

*/


std::string solution(){
	mpz_class D = 8;

	mpz_class target;
	mpz_ui_pow_ui(target.get_mpz_t(), 10, 12);
	
	
	mpz_class S0 = 3;
	mpz_class R0 = 1;
	mpz_class S = S0;
	mpz_class R = R0;
	mpz_class B = 0;
	while(B + R < target){
		mpz_class temp = S0*S + D*R0*R;
		R = S0*R + R0*S;
		S = temp;
		B = 2*R+1 + sqrt(8*R*R + 1);
		B /= 2;
		//std::cout << S.get_str() << " / " << R.get_str() << std::endl;
		//std::cout << R.get_str() << " + " << B.get_str() << std::endl;
	}

	return B.get_str();
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
