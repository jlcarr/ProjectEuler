// Solution to Project Euler problem 26

#include <iostream>
#include <chrono>

#include <set>

/*
Use long division to find cycles
*/

int solution(){
	int result = 0;
	int max_len = 0;
	for (int i=2; i<1000; i++){
		std::set<int> remainders;
		remainders.clear();
		
		int r = 1;
		while(remainders.find(r) == remainders.end()){
			//std::cout << r << "-";
			remainders.insert(r);
			r = (10*r)%i;
		}
		int cycle_len = remainders.size() - std::distance(remainders.begin(),remainders.find(r));
		if (cycle_len>max_len){
			result = i;
			max_len = cycle_len;
		}
		//std::cout << "  " << i << " : " << cycle_len << std::endl;
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
