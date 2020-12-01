// Solution to Project Euler problem 78

#include <iostream>
#include <chrono>


#include <set>
#include <map>
#include <vector>


/*
Compute partition function using Euler's formula
Cache subsolutions

*/


long partitions(long n, long mod, std::map<long,long> &subsols){
	if(subsols.find(n) != subsols.end()) return subsols[n];
	long result = 0;
	// positives
	for(long k=1; k*(3*k-1)/2 <= n; k++){ 
		result += (2*(k%2)-1) * partitions(n -  k*(3*k-1)/2 , mod, subsols);
		result %= mod;
	}
	// negatives
	for(long k=1; k*(3*k+1)/2 <= n; k++){
		result += (2*(k%2)-1) * partitions(n -  k*(3*k+1)/2 , mod, subsols);
		result %= mod;
	}
	
	subsols[n] = result;
	return result;
}


long solution(){
	int target = 1000*1000;
	std::map<long,long> subsols = {{0,1}};
	
	//std::cout <<  partitions(5, target, subsols) << std::endl;

	long n = 1;
	while(true){
		long p = partitions(n, target, subsols);
		//std::cout << "p(" << n << ") = " << p << std::endl;
		if(p%target == 0) return n;
		n++;
	}

	return -1;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
