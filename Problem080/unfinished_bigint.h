#include <vector>

class bigint : 
public std::vector<int> {
	public:
		bool sign;
		
		bigint();
		bigint(int x);
		bigint(int n_digits, int digit);

		// operations
		bigint abs();
		bigint operator+(bigint const &other);
		
};

bigint::bigint(){
	sign = true;
}

bigint::bigint(int x){
	// Handle sign
	sign = (x>=0);
	if(!sign) x *= -1;
	// Fill digits
	for(; x>0; x /= 2) this->push_back(x%2);
}

bigint::bigint(int n_digits, int digits): 
std::vector<int>(n_digits, digits){
	sign = true;
}

bigint bigint::abs(){
	bigint temp = *this;
	temp.sign = true;
	return temp;
}


bigint bigint::operator+(bigint const &other){
	bigint result;

	// check if there are signs
	//if(!(this->sign) || !(other.sign)){
		
	//}

	/* bigInt temp;
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
	}*/

	auto it_this = this->begin();
	auto it_other = other.begin();
	int carry = 0;
	while(it_this != this->end() || it_other != other.end()){
		result.push_back(carry);
		if(it_this != this->end()) {
			result.back() += *it_this;
			it_this++;
		}
		if(it_other != other.end()){
			result.back() += *it_other;
			it_other++;
		}
		carry = result.back()/2;
		result.back() %= 2;
	}
	if(carry>0) result.push_back(carry);
	return result;
}

bigint bigint::operator+(bigint const &other){
	bigint result;


std::ostream &operator<<(std::ostream &os, bigint const &obj) {
	std::string result;
	if(!obj.sign) result += "-";
	for(auto it = obj.rbegin(); it != obj.rend(); it++) result += std::to_string(*it);
	return os << result;
}
