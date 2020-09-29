// Solution to Project Euler problem 22

#include <iostream>
#include <chrono>

#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


long solution(){ 
	std::vector<std::string> names; 
	std::ifstream file("p022_names.txt", std::ios::in);
	names.push_back("");
	while(!file.eof()){
		char c = file.get();
		if (c == ',') names.push_back("");
		if (c < 'A' || c > 'Z') continue;
		names.back().push_back(c);
	}
	std::sort(names.begin(), names.end());

	long result = 0;
	for (int i=0; i<names.size(); i++){ 
		int temp = 0;
		for (auto c_it = names[i].cbegin(); c_it != names[i].cend(); ++c_it){
			//result += (long) (i+1)*(*c_it-'A'+1);	
			temp += *c_it-'A'+1;
		}
		result += (long) (i+1)*temp;
		//std::cout << i+1 << " : " << names[i] << " : " << temp << " : " << result << std::endl;
	}

	//for (int i=0; i<names.size(); i++) std::cout << names[i] << std::endl;
	
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
