// Solution to Project Euler problem 66

#include <iostream>
#include <chrono>


#include <math.h>
#include <vector>
#include <map>

/*
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


class bigInt{
	public:
		std::vector<int> digits;

		bigInt(int x=0){
			for(; x>0; x/=10) digits.push_back(x%10);
		}

		bigInt operator+(bigInt const &other){
			bigInt result;
			auto it_this = digits.begin();
			auto it_other = other.digits.begin();
			int carry = 0;
			while(it_this != digits.end() || it_other != other.digits.end()){
				result.digits.push_back(carry);
				if(it_this != digits.end()) {
					result.digits.back() += *it_this;
					it_this++;
				}
				if(it_other != other.digits.end()){
					result.digits.back() += *it_other;
					it_other++;
				}
				carry = result.digits.back()/10;
				result.digits.back() %= 10;
			}
			if(carry>0) result.digits.push_back(carry);
			return result;
		}

		bigInt operator*(bigInt const &other){
			bigInt result;
			for(int i = 0; i < digits.size(); i++){
				for(int j = 0; j < other.digits.size(); j++){
					while(i+j >= result.digits.size()) result.digits.push_back(0);
					result.digits[i+j] += digits[i]*other.digits[j];
				}
			}
			int carry = 0;
			for(int i=0; i < result.digits.size(); i++){
				result.digits[i] += carry;
				carry = result.digits[i]/10;
				result.digits[i] %= 10;
			}
			while(carry>0){
				result.digits.push_back(carry%10);
				carry /= 10;
			}
			return result;
		}

		bool operator==(const bigInt& other) {
			return digits == other.digits;
		}

		bool operator<(const bigInt& other) {
			if (digits.size() != other.digits.size()) return digits.size() < other.digits.size();
			for(int i=digits.size()-1; i>=0; i--){
				if(digits[i] != other.digits[i]) return digits[i] < other.digits[i];
			}
			return false;
		}
};


std::ostream &operator<<(std::ostream &os, bigInt const &obj) {
	std::string result;
	for(auto it = obj.digits.rbegin(); it != obj.digits.rend(); it++) result += std::to_string(*it);
	return os << result;
}




int solution(){
	int target = 1000;
	int result = 0;
	bigInt max_x(0);

	for(int N=2; N <= target; N++){
		int z = (int)sqrt(N);
		// No perfect squares
		if(z*z == N) continue;

		int n = 0;
		int d = 1;
		bigInt n_curr, n_p(1), n_pp(0); 
		bigInt d_curr, d_p(0), d_pp(1);
		bool is_sol = false;
		while(!is_sol){
			// Compute a values
			int a = (n+z)/d;
			int n_temp = a*d - n;
			d = (N - (n - a * d)*(n - a * d))/d;
			n = n_temp;

			// Compute next iterations
			n_curr = bigInt(a)*n_p + n_pp;
			d_curr = bigInt(a)*d_p + d_pp;

			n_pp = n_p;
			d_pp = d_p;
			n_p = n_curr;
			d_p = d_curr;
		
			// Check solution
			is_sol = n_curr*n_curr == bigInt(N)*d_curr*d_curr + bigInt(1);
			//std::cout << is_sol << " " << n_curr << " == " << (bigInt(N)*d_curr*d_curr + bigInt(1)) << std::endl;
			//std::cout << n_curr << "/" << d_curr << " from: " << a << " + (" << n << " + z)/" << d << std::endl;
		}
		//std::cout <<  n_curr << "^2 - " << N << " * " << d_curr << "^2 == 1" << std::endl;
		if(max_x < n_curr) {
			max_x = n_curr;
			result = N;
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
