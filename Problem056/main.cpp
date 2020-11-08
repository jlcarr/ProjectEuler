// Solution to Project Euler problem 56

#include <iostream>
#include <chrono>

#include <vector>
#include <math.h>

/*
Solution approach
Long multiplication
max len = 2*100 + 1= 201

a*b* len*len
100*100 * 200*200
*/

std::vector<int> long_mul(std::vector<int> a, std::vector<int>b){
	std::vector<int> result;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			while(i+j >= result.size()) result.push_back(0);
			result[i+j] += a[i]*b[j];
		}
	}
	int carry = 0;
	for(int i=0; i<result.size(); i++){
		result[i] += carry;
		carry = result[i]/10;
		result[i] %= 10;
	}
	while(carry>0){
		result.push_back(carry%10);
		carry /= 10;
	}

	//std::cout << "a = ";
	//for(auto it = a.rbegin(); it != a.rend(); it++) std::cout << *it;
	//std::cout << " b = ";
	//for(auto it = b.rbegin(); it != b.rend(); it++) std::cout << *it;
	//std::cout << " res = ";
	//for(auto it = result.rbegin(); it != result.rend(); it++) std::cout << *it;
	//std::cout << " asize = " << a.size() << " bout = " << b.size() << "ressize " << result.size();
	//std::cout << std::endl;

	return result;
}

std::vector<int> long_exp(std::vector<int> a, int b){
	//std::cout << (b%2) << "b = " << b << " a = ";
	//for(auto it = a.rbegin(); it != a.rend(); it++) std::cout << *it;
	//std::cout << std::endl;

	if(b==0) return std::vector<int>({1});
	else if(b%2) return long_mul(a,long_exp(a,b-1));
	else {
		std::vector<int> sub_res = long_exp(a,b/2);
		return long_mul(sub_res,sub_res);
	}
}

int solution(){
	int n = 100;
	int result = 0;

	for(int a = 1; a < n; a++){
		for(int b = 1; b < n; b++){
			std::vector<int> a_vec;
			for(int temp=a; temp>0; temp/=10) a_vec.push_back(temp%10);
			std::vector<int> op_result = long_exp(a_vec,b);
			//std::cout << a << " ^ " << b << " = ";
			//for(auto it = op_result.rbegin(); it != op_result.rend(); it++) std::cout << *it;
			//std::cout << std::endl;
			int dig_sum = 0;
			for(auto it = op_result.begin(); it != op_result.end(); it++) dig_sum += *it;
			if(dig_sum>result) result = dig_sum;
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
