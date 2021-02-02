// Solution to Project Euler problem 89

#include <iostream>
#include <chrono>

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

/*
Roman numerals

*/

int decode_numeral(std::string numeral){
	const std::map<char,int> val = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
	int result = 0;
	while(numeral.length() > 0){
		int temp = val.at(numeral.back());
		numeral.pop_back();
		if(!numeral.empty() && val.at(numeral.back()) < temp){
			temp -= val.at(numeral.back());
			numeral.pop_back();
		}
		result += temp;
	}
	return result;
}

std::string encode_numeral(int n){
	std::string result = "";
	// 1000 = M
	while(n/1000 > 0){
		result.append("M");
		n -= 1000;
	}
	// 900 = CM
	if (n >= 900){
		result.append("CM");
		n -= 900;
	}
	// 500 = D
	if (n >= 500){
		result.append("D");
		n -= 500;
	}
	// 400 = CD
	if (n >= 400){
		result.append("CD");
		n -= 400;
	}
	// 100 = C
	while(n/100 > 0){
		result.append("C");
		n -= 100;
	}
	// 90 = XC
	if (n >= 90){
		result.append("XC");
		n -= 90;
	}
	// 50 = L
	if (n >= 50){
		result.append("L");
		n -= 50;
	}
	// 40 = XL
	if (n >= 40){
		result.append("XL");
		n -= 40;
	}
	// 10 = X
	 while(n/10 > 0){
		result.append("X");
		n -= 10;
	}
	// 9 = IX
	if (n >= 9){
		result.append("IX");
		n -= 9;
	}
	// 5 = V
	if (n >= 5){
		result.append("V");
		n -= 5;
	}
	// 4 = IV
	if (n >= 4){
		result.append("IV");
		n -= 4;
	}
	// 1 = I
	while(n/1 > 0){
		result.append("I");
		n -= 1;
	}

	return result;
}

int solution(){ 
	std::ifstream file("p089_roman.txt", std::ios::in);
	std::vector<std::string> numerals;
	std::string numeral;
	while(std::getline(file, numeral)){
		numerals.push_back(numeral);
	}

	//for(auto it = numerals.begin(); it != numerals.end(); it++) std::cout << *it << " = " << decode_numeral(*it) << " = " << encode_numeral(decode_numeral(*it)) << std::endl;

	int result = 0;
	for(auto it = numerals.begin(); it != numerals.end(); it++) result += it->length() - encode_numeral(decode_numeral(*it)).length();

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
