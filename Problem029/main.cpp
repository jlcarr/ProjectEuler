// Solution to Project Euler problem 29

#include <iostream>
#include <chrono>

#include <set>
#include<map>

/*
create ordered set of a
loop a 
pop powers of a less than 100
loop b on a powers and add powers to tracking set
tracking set contains the answer
*/

int solution(){
	long n = 100;
	std::set<int> a_set;
	for (int i=2; i<=n; i++) a_set.insert(i);
	
	std::map<int,std::set<int>> powers;
	
	while (!a_set.empty()){
		int a = *a_set.begin();
		int plus_pow = 1;
		int a_pow = a;
		while (a_pow <= n){
			a_set.erase(a_pow);
			for(int b=2; b<=n; b++) powers[a].insert(plus_pow*b);
			//std::cout << a_pow << std::endl;

			a_pow *= a;
			plus_pow++;
		}
		//std::cout << a << " : " <<  powers[a].size() << std::endl;
	}

	int result = 0;
	for(auto it_a = powers.begin(); it_a != powers.end(); it_a++)
		for(auto it_p = it_a->second.begin(); it_p != it_a->second.end(); it_p++)
			result += 1;

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
