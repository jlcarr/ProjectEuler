// Solution to Project Euler problem 81

#include <iostream>
#include <chrono>

#include <fstream>
#include <string>

/*
Dijkstra's algorithm, same as 67

*/

int solution(){ 
	int n = 80;
	//int n = 5;
	//std::ifstream file("test_matrix.txt", std::ios::in);
	std::ifstream file("p081_matrix.txt", std::ios::in);
	int grid[n][n];
	int i=0, j=0;
	std::string number = "";
	char c;
	while(!file.eof() && i < n){
		c = file.get();
		if(c < '0' || c > '9'){
			grid[i][j] = std::stoi(number);
			j++;
			if(j==n) i++;
			j %= n;
			number = "";
			continue;
		}
		number += c;
	}


	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) std::cout << grid[i][j] << ", ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/
	
	// Djikstra traversal
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			int best = 0;
			if(i > 0) best = grid[i-1][j];
			if(j > 0 && (grid[i][j-1] < best || !best)) best = grid[i][j-1];
			grid[i][j] += best;
		}
	}
	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) std::cout << grid[i][j] << ", ";
		std::cout << std::endl;
	}
	*/

	return grid[n-1][n-1];
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
