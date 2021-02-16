// Solution to Project Euler problem 99

#include <iostream>
#include <chrono>


#include <fstream>
#include<string>

#include <math.h>

/*
Use logarithms, hopefully will be enough precision, we shall see

*/


int solution(){
	std::ifstream file("p099_base_exp.txt", std::ios::in);

	double max_val = 0;
	int result;

	// Parse the dataset
	int line_number = 0;
	std::string line;
	while(std::getline(file,line)){
		line_number++;
		double base = 0;
		double exp = 0;
		auto c_it=line.begin();
		for(; *c_it!=','; c_it++) base = 10*base + (double)(*c_it - '0');
		for(c_it++; c_it!=line.end(); c_it++) exp = 10*exp + (double)(*c_it - '0');
		double log_val = exp * log(base);
		//std::cout << base << " ^ " << exp << std::endl;
		if(log_val > max_val){
			max_val = log_val;
			result = line_number;
		}
	}
	file.close();

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
