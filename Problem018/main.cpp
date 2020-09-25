// Solution to Project Euler problem 18

#include <iostream>
#include <chrono>

int solution(){ 
	int n = 15;
	FILE* fp = fopen("grid.txt","r");
	int grid[n][n];
	for (int i=0; i<n; i++) 
		for (int j=0; j<=i; j++) 
			fscanf(fp, "%2d", &grid[i][j]);
	
	// Djikstra traversal
	for (int i=1; i<n; i++){
		 grid[i][0] += grid[i-1][0];
		 grid[i][i] += grid[i-1][i-1];
		for (int j=1; j<=i-1; j++){
			grid[i][j] += (grid[i-1][j] > grid[i-1][j-1])? grid[i-1][j] : grid[i-1][j-1] ;
		}
	}
	/*for (int i=0; i<n; i++){
		for (int j=0; j<=i; j++) std::cout << grid[i][j] << ", ";
		std::cout << std::endl;
	}*/

	int result = 0;
	for(int i=0; i<n; i++) if(grid[n-1][i]>result) result = grid[n-1][i];
	
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
