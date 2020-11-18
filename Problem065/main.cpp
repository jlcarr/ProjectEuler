// Solution to Project Euler problem 65

#include <iostream>
#include <chrono>


#include <math.h>
#include <vector>
#include <map>

/*
on each step
prev = n/d
next = a_k + 1/prev = a_k + d/n
next = (a_k * n + d)/n

n = a_k * n + d
d = n
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
};


std::ostream &operator<<(std::ostream &os, bigInt const &obj) {
	std::string result;
	for(auto it = obj.digits.rbegin(); it != obj.digits.rend(); it++) result += std::to_string(*it);
	return os << result;
}




int solution(){
	int target = 100;

	bigInt n = 1;
	bigInt d = 1;
	for(int step = 1; step <= target; step++){
		bigInt a(step%3 ? 1 : 2*step/3);
		bigInt temp_n = a*n+d;
		d = n;
		n = temp_n;
		//std::cout << n << "/" << d << std::endl;
	}

	int result = 0;
	for(auto dig = n.digits.begin(); dig != n.digits.end(); dig++) result += *dig;
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
