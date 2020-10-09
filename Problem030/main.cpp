// Solution to Project Euler problem 30

#include <iostream>
#include <chrono>

#include <set>
#include<map>

/*
n=5
max r s.t.
r*9^n >= 10^(r - 1)
r ~ n+1

5*9^5 >= 10^(5-1)


This given max number of digits,
Then need to generate the n choose r with replacement (multichoose)
Get the values of each and check if meets criterion

*/

int solve_multichoose(int pow, int k, std::set<int> n, std::map<int,int>multi_choice){
	//std::cout << k << " : ";
	//for(auto choices = multi_choice.begin(); choices != multi_choice.end(); choices++) 
	//	std::cout << choices->first << "=" << choices->second << " ";
	//std::cout << std::endl;
	if (k==0){
		//check solution
		// first get powsum
		int dig_pow_sum = 0;
		for(auto choices = multi_choice.begin(); choices != multi_choice.end(); choices++){
			int dig_pow = 1;
			for(int i=0; i<pow; i++) dig_pow *= choices->first;
			dig_pow_sum += dig_pow * choices->second;
		}

		//std::cout << dig_pow_sum << std::endl; 
		//for(auto choices = multi_choice.begin(); choices != multi_choice.end(); choices++) 
		//	std::cout << choices->first << "=" << choices->second << " ";
		//std::cout << std::endl;

		// Then check the validity
		int result = dig_pow_sum;
		while (dig_pow_sum){
			int dig = dig_pow_sum%10;
			dig_pow_sum /= 10;
			if (multi_choice.find(dig) == multi_choice.end() || !multi_choice[dig]) return 0;
			multi_choice[dig]--;
			/*if(result==1634){ 
				std::cout << dig << " : " << (multi_choice.find(dig) == multi_choice.end()) << std::endl;
				std::cout << dig_pow_sum << std::endl; 
				for(auto choices = multi_choice.begin(); choices != multi_choice.end(); choices++) 
					std::cout << choices->first << "=" << choices->second << " ";
				std::cout << std::endl;
			}*/
		}
		for(auto choices = ++multi_choice.begin(); choices != multi_choice.end(); choices++)
			if(choices->second > 0) return 0;
		//std::cout << result << std::endl;
		//std::cout << "kept" << std::endl;
		return result;
	}
	int result = 0;
	int val = *n.begin();
	n.erase(val);
	if (n.empty()){
		 multi_choice[val] = k;
		return solve_multichoose(pow, 0, n, multi_choice);;
	}
	for(int i=0; i<=k; i++){
		multi_choice[val] = i;
		result += solve_multichoose(pow, k-i, n, multi_choice);
	}
	return result;
}

int solution(){
	int n=5;
	int r = n+1;

	return solve_multichoose(n, r, std::set<int>({0,1,2,3,4,5,6,7,8,9}), std::map<int,int>()) - 1;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
