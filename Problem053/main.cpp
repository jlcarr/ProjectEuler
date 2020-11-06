// Solution to Project Euler problem 53

#include <iostream>
#include <chrono>

#include <vector>
/* 
target = 1,000,000
Iterate down the triangle outside the target
Use Pascale's Rule for efficiency
*/

long solution(){
	int n_max = 100;
	long target = 1000*1000;
	int result = 0;

	std::vector<long> row;
	std::vector<long> prev_row = {1,2};
	for(int n=3; n<=n_max; n++){
		// compute current row
		row.clear();
		row.push_back(1);
		for(int r=0; r < prev_row.size()-1 && prev_row[r]+prev_row[r+1] <= target; r++ ){
			row.push_back(prev_row[r]+prev_row[r+1]);
		}
		if(!(n%2) && 2*row.size() == n) row.push_back(2*prev_row.back());
		int temp = n+1 - 2*((int)row.size());
		if(temp>0) result += temp;
		//for(auto it = row.begin(); it != row.end(); it++) std::cout << *it << ",";
		//std::cout << std::endl;
		//std::cout << "n = " << n << " count = " << temp << " result = " << result << std::endl;
		prev_row = row;
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
