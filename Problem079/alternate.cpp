// Solution to Project Euler problem 79

#include <iostream>
#include <chrono>

#include <fstream>
#include <set>
#include <list>

/*

*/

std::list<long> search(std::set<std::list<long>> key_tests){
	if(key_tests.empty()) return std::list<long>();
	std::set<long> dig_pool;
	for(auto k = key_tests.begin(); k != key_tests.end(); k++) dig_pool.insert(k->front());
	// Search all possible first digits
	std::list<long> result;
	for(auto dig = dig_pool.begin(); dig != dig_pool.end(); dig++) {
		// For each key, erase that first digit if available.
		std::set<std::list<long>> temp_key_tests = {};
		for(auto k = key_tests.begin(); k != key_tests.end(); k++){
			std::list<long> test = *k;
			if(test.front() == *dig) test.pop_front();
			if(test.empty()) continue;
			temp_key_tests.insert(test);
		}
		// search
		std::list<long> temp_result = search(temp_key_tests);
		temp_result.push_front(*dig);
		// check if is optimal
		if(result.empty() || result.size() > temp_result.size()) result = temp_result;
	}
	return result;
}

int solution(){ 
	std::ifstream file("p079_keylog.txt", std::ios::in);
	//std::ifstream file("test.txt", std::ios::in);
	std::set<std::list<long>> key_tests;

	// read file
	long read_value;
	while(file >> read_value){
		std::list<long> temp = {(read_value/100)%10, (read_value/10)%10, read_value%10};
		key_tests.insert(temp);
	}

	//for(auto k = key_tests.begin(); k != key_tests.end(); k++){
	//	for(auto it = k->begin(); it != k->end(); it++) std::cout << *it;
	//	std::cout << std::endl;
	//}

	std::list<long> temp_result = search(key_tests);
	for(auto it = temp_result.begin(); it != temp_result.end(); it++) std::cout << *it;
	std::cout << std::endl;

	return 0;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
