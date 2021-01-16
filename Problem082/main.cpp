// Solution to Project Euler problem 82

#include <iostream>
#include <chrono>

#include <fstream>
#include <string>

/*
Similar to 81, but with a little extra

*/

int solution(){ 
	int n = 80;
	//int n = 5;
	//std::ifstream file("test_matrix.txt", std::ios::in);
	std::ifstream file("p082_matrix.txt", std::ios::in);
	int grid[n][n], result_grid[n][n];
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
	
	// Djikstra traversal with added step
	// initial values
	for (int i=0; i<n; i++) result_grid[i][0] = grid[i][0];
	// Traversal
	for (int j=1; j<n; j++){
		// default reached by left
		for (int i=0; i<n; i++) result_grid[i][j] = result_grid[i][j-1] + grid[i][j];

		// try above		
		for (int i=1; i<n; i++){
			if(result_grid[i][j] > result_grid[i-1][j] + grid[i][j]) result_grid[i][j] = result_grid[i-1][j] + grid[i][j];
		}
		for (int i=n-2; i>=0; i--){
			if(result_grid[i][j] > result_grid[i+1][j] + grid[i][j]) result_grid[i][j] = result_grid[i+1][j] + grid[i][j];
		}
	}
	
	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) std::cout << result_grid[i][j] << ", ";
		std::cout << std::endl;
	}
	*/
	
	int result = result_grid[0][n-1];
	for(int i=0; i<n; i++) if(result > result_grid[i][n-1]) result = result_grid[i][n-1];

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
