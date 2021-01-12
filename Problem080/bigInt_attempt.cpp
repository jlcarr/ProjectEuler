// Solution to Project Euler problem 80

#include <iostream>
#include <chrono>


#include <math.h>
#include <vector>
#include <map>

/*
For simplicity, gonna try the bisection method
Added subtraction via 10s complement


*/


class bigInt{
	public:
		std::vector<int> digits;
		bool positive;

		bigInt(int x=0){
			positive = (x>=0);
			if(!positive) x *= -1;
			for(; x>0; x/=10) digits.push_back(x%10);
		}

		bigInt abs(){
			bigInt temp = *this;
			temp.positive = true;
			return temp;
		}

		bigInt operator+(bigInt const &other){
			bigInt result;
			bigInt temp;
			// handle negatives
			if(!positive && other.positive){
				result = *this;
				result.positive = true;
				temp = other;
				return temp - result;
			}
			else if (positive && !other.positive){
				result = other;
				result.positive = true;
				return *this - result;
			}
			else if (!positive && !other.positive){
				temp = *this;
				result = other;
				result.positive = true;
				temp.positive = true;
				result = temp + result;
				result.positive = false;
				return result;
			}

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

		bigInt operator-(bigInt const &other){
			bigInt result;
			bigInt temp;
			// handle negatives
			if(positive && !other.positive){
				temp = other;
				temp.positive = true;
				return *this + temp;
			}
			else if (!positive && other.positive){
				result = *this;
				result.positive = true;
				temp = other;
				temp = result + temp;
				temp.positive = false;
				return temp;
			}
			else if (!positive && !other.positive){
				temp = other;
				result = *this;
				temp.positive = true;
				result.positive = true;
				return temp - result;
			}

			// 10s complement the other
			for(auto it = other.digits.begin(); it != other.digits.end(); it++) temp.digits.push_back(9 - *it);
			while(temp.digits.size() < this->digits.size()) temp.digits.push_back(9);
			temp = temp + bigInt(1);
			while(temp.digits.back() == 0) temp.digits.pop_back();
			
			// perform addition on the 10s complement for subtraction
			temp = *this + temp;

			if(*this < other){
				// 10s complement to get back to the 
				for(auto it = temp.digits.begin(); it != temp.digits.end(); it++) result.digits.push_back(9 - *it);
				result = result + bigInt(1);
				result.positive = false;
			}
			else {
				result = temp;
				result.digits.pop_back();
			}

			while(result.digits.back() == 0) result.digits.pop_back();
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

			if(this->positive ^ other.positive) result.positive = false;
			return result;
		}

		bigInt operator/(bigInt const &other){
			bigInt divisor = other;
			// Handle negatives first
			if(*this < other) return bigInt();

			bigInt result;			
	
			// Long division, base 10, algorithm form with restoring
			bigInt remainder = *this;
			while(remainder.abs() > divisor.abs()){
				int div_digs = 0;
				int partial_remainder = 0;
				while(partial_remainder / other.digits.back() == 0){
					div_digs++;
					partial_remainder = 10 * partial_remainder + remainder.digits[remainder.digits.size() - div_digs];
				}
				int digit = partial_remainder / other.digits.back();			
	
				// prepare temp_result;
				bigInt temp_result;
				temp_result.digits = std::vector<int>(remainder.digits.size() - div_digs, 0);
				temp_result.digits.back() = digit;
				temp_result.positive = remainder.positive;
			
				result = result + temp_result;
				if(!result.positive) std::cout << "-";
				for(auto it = result.digits.rbegin(); it != result.digits.rend(); it++) std::cout << *it;
				std::cout << " RESULT" << std::endl;

				// compute new remainder
				remainder = remainder - (temp_result * other);
				bigInt dummy = temp_result * other;
				if(!dummy.positive) std::cout << "-";
				for(auto it = dummy.digits.rbegin(); it != dummy.digits.rend(); it++) std::cout << *it;
				std::cout << " SUB" << std::endl;
				if(!remainder.positive) std::cout << "-";
				for(auto it = remainder.digits.rbegin(); it != remainder.digits.rend(); it++) std::cout << *it;
				std::cout << " REMAINDER" << std::endl;
			}
			return result;
		}

		bool operator==(const bigInt& other) {
			return digits == other.digits;
		}

		bool operator<(const bigInt& other) {
			// Hangle negatives
			if (digits.size() != other.digits.size()) return digits.size() < other.digits.size();
			for(int i=digits.size()-1; i>=0; i--){
				if(digits[i] != other.digits[i]) return digits[i] < other.digits[i];
			}
			return false;
		}

		bool operator>(const bigInt& other) {
			return !(*this < other);
		}
};


std::ostream &operator<<(std::ostream &os, bigInt const &obj) {
	std::string result;
	if(!obj.positive) result += "-";
	for(auto it = obj.digits.rbegin(); it != obj.digits.rend(); it++) result += std::to_string(*it);
	return os << result;
}


bigInt bisection_root(bigInt n, int precision){
	bigInt lower(0);
	bigInt upper(n);
	return lower;	
}



int solution(){
	int target = 1000;
	int result = 0;
	bigInt max_x(0);

	std::cout << bigInt(871392) / bigInt(57) << std::endl;
	//std::cout << bigInt(16000) - bigInt(800) << std::endl;
/*
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
*/
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
