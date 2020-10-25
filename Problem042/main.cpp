// Solution to Project Euler problem 42

#include <iostream>
#include <chrono>

#include <fstream>
#include <list>
#include <string>
#include <math.h>


/*
inverse triangular n*(n+1)/2 = x
quadratic formula
n*n^2 + n - 2*x = 0
n = -1 +- sqrt(1+8*x)
take positive.
check accuracy by inversion
*/


int solution(){ 
	std::list<std::string> words; 
	std::ifstream file("p042_words.txt", std::ios::in);
	words.push_back("");
	while(!file.eof()){
		char c = file.get();
		if (c == ',') words.push_back("");
		if (c < 'A' || c > 'Z') continue;
		words.back().push_back(c);
	}

	int result = 0;
	for (auto word = words.begin(); word != words.end(); word++){ 
		int temp = 0;
		for (auto c_it = word->cbegin(); c_it != word->cend(); ++c_it){
			//result += (long) (i+1)*(*c_it-'A'+1);	
			temp += *c_it-'A'+1;
		}
		//std::cout << *word << " = " << temp << std::endl;
		int n = (int)round((-1.0 + sqrt(1+8*temp))/2.0);
		//std:: cout << n << " : " << n*n + n - 2*temp << std::endl;
		if(n*n + n - 2*temp == 0) result++;
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
