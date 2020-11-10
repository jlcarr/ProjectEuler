// Solution to Project Euler problem 57

#include <iostream>
#include <chrono>


#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

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
};

std::ostream &operator<<(std::ostream &os, bigInt const &obj) {
	std::string result;
	for(auto it = obj.digits.rbegin(); it != obj.digits.rend(); it++) result += std::to_string(*it);
	return os << result;
}


int solution(){
	int n = 1000;
	bigInt a(1);
	bigInt b(1);
	
	int result = 0;
	for(int i=0; i<n; i++){
		// update
		bigInt temp = a+b+b;
		b = a+b;
		a = temp;

		// Get gcd via euclid's
		// Actually unneeded
		/*
		int gcd = a;
		int extra = b;
		while (extra){
			temp = extra;
			extra = gcd % extra;
			gcd = temp;
		}
		
		// lowest terms
		std::cout << gcd << std::endl;
		a /= gcd;
		b /= gcd;
		*/
		
		//std::cout << a << " / " << b << std::endl;

		if(a.digits.size() > b.digits.size()) result++;
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
