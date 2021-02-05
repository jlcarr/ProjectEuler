// Solution to Project Euler problem 92

#include <iostream>
#include <chrono>


#include <list>
#include <map>


/*
Direct approach caching as in previous solutions

*/


int solution(){
	int target = 10*1000*1000;

	std::map<int,int> chains = {{1,1},{89,89}};
	for(int n=1; n<=target; n++){
		//std::cout << n << std::endl;
		int temp = n;
		std::list<int> chain_handle;
		while(chains.find(temp) == chains.end()){
			chain_handle.push_back(temp);
			int i = temp;
			for(temp=0; i>0; i/=10) temp += (i%10)*(i%10);
		}
		for(auto it = chain_handle.begin(); it != chain_handle.end(); it++) chains[*it] = chains[temp];
		chain_handle.clear();
	}
	int result = 0;
	for(auto it = chains.begin(); it != chains.end() && it->first <= target; it++) if(it->second == 89) result++;
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
