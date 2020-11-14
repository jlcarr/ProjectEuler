// Solution to Project Euler problem 62

#include <iostream>
#include <chrono>


#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

/*
translate expression to
x = 1+1/(1+x)
a/b <= 1+1/(1+a/b) = 1+b/(b+a)
a <= a+2*b
b <= a+b

then euclid's gcd for lowest terms
NOTE: actually test show this isn't needed
Just need big int addition
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


bigInt solution(){
	std::map<std::vector<int>,int> digit_counts;
	std::map<std::vector<int>,bigInt> orig;

	int num = 1;
	while(num < 100000){
		// Perform cube
		bigInt temp = bigInt(num);
		bigInt cube = temp*temp*temp;
		//std::cout << cube << std::endl;
		// Get digit counts
		std::vector<int> digit_count(10,0);
		for(auto dig = cube.digits.begin(); dig != cube.digits.end(); dig++) digit_count[*dig]++;
		digit_counts[digit_count]++;
		if(orig.find(digit_count) == orig.end()) orig[digit_count] = cube;
		if(digit_counts[digit_count] == 5) return orig[digit_count];
		num++;
	}

	return bigInt(0);
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
