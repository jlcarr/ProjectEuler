// Solution to Project Euler problem 73

#include <iostream>
#include <chrono>

#include <list>
#include <vector>
#include <map>
#include <set>

/*
Solution approach
Use Stern–Brocot tree ideas
primarily mediants

*/


int tree_count(int target_d, int n_lower, int d_lower, int n_upper, int d_upper){
	int n_mediant = n_lower + n_upper;
	int d_mediant = d_lower + d_upper;
		
	if(d_mediant > target_d) return 0;
	//std::cout << n_mediant << "/" << d_mediant << std::endl;

	int lower_result = tree_count(target_d, n_lower, d_lower, n_mediant, d_mediant);
	int upper_result = tree_count(target_d, n_mediant, d_mediant, n_upper, d_upper);
	return 1 + lower_result + upper_result;
}


int solution(){ 
	int d_max = 12000;
	int n_lower = 1, d_lower = 3;
	int n_upper = 1, d_upper = 2;

	return tree_count(d_max, n_lower, d_lower, n_upper, d_upper);
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
