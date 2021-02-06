// Solution to Project Euler problem 93

#include <iostream>
#include <chrono>


#include <list>
#include <set>


/*
the number of abcd choices is < 10^4 = 10000
The number of expression trees for 4 numbers (leaves) is 5
The number of permutations of 4 digits on those expression trees is 4! = 24
This gives 1.2 million computations to do: quite feasible.
Furthermore because of the a<b<c<d ordering and commutativity of * and +, the number is actually quite a bit less

Just avoid division by 0
Also not checking fractional numbers.

*/

std::set<int> eval(std::list<int> nums){
	if(nums.size() == 1) return {*(nums.begin())};
	
	std::set<int> result;
	for(auto n1 = nums.begin(); n1 != nums.end(); n1++){
		for(auto n2 = n1; ++n2 != nums.end();){
			std::list<int> temp;
			for(auto it = nums.begin(); it != nums.end(); it++) if(it != n1 && it != n2) temp.push_back(*it);
			// +
			temp.push_back(*n1 + *n2);
			std::set<int> temp_result = eval(temp);
			result.insert(temp_result.begin(), temp_result.end());
			temp.pop_back();
			// - order 1
			temp.push_back(*n1 - *n2);
			temp_result = eval(temp);
			result.insert(temp_result.begin(), temp_result.end());
			temp.pop_back();
			// - order 2
			temp.push_back(*n2 - *n1);
			temp_result = eval(temp);
			result.insert(temp_result.begin(), temp_result.end());
			temp.pop_back();
			// *
			temp.push_back(*n1 * *n2);
			temp_result = eval(temp);
			result.insert(temp_result.begin(), temp_result.end());
			temp.pop_back();
			// / order 1
			if(*n2 != 0 && (*n1)%(*n2) == 0){
				temp.push_back(*n1 / *n2);
				temp_result = eval(temp);
				result.insert(temp_result.begin(), temp_result.end());
				temp.pop_back();
			}
			// / order 2
			if(*n1 != 0 && (*n2)%(*n1) == 0){
				temp.push_back(*n2 / *n1);
				temp_result = eval(temp);
				result.insert(temp_result.begin(), temp_result.end());
				temp.pop_back();
			}
		}
	}
	return result;
}

int solution(){
	int max_count = 0;
	int result = 0;
	for(int d = 3; d <=9; d++){
		for(int c = 2; c < d; c++){
			for(int b = 1; b < c; b++){
				for(int a = 0; a < b; a++){
					std::set<int> temp = eval({a,b,c,d});
					int count = 0;
					for(auto it = temp.find(1); it != temp.end() && *it == count+1; it++) count++;
					if(count >= max_count){
						max_count = count;
						result = 1000*a + 100*b + 10*c + d;
					}
					//for(auto it = temp.begin(); it != temp.end(); it++) std::cout << *it << ",";
					//std::cout << " : " << (1000*a + 100*b + 10*c + d) << " = " << count << std::endl;
				}
			}
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
