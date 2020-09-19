// Solution to Project Euler problem 11

#include <iostream>
#include <chrono>

long solution(){ 
	FILE* fp = fopen("grid.txt","r");
	int grid[20][20];
	for (int i=0; i<20; i++) 
		for (int j=0; j<20; j++) 
			fscanf(fp, "%2d", &grid[i][j]);
	int result = 0;
	// Horizontal
	for (int i=0; i<20; i++) 
		for (int j=0; j<20-4; j++) {
			int temp = 1;
			for (int k=0; k<4; k++) temp *= grid[i][j+k];
			if(temp>result) result = temp;
		}
	// Vertical
	for (int i=0; i<20-4; i++) 
		for (int j=0; j<20; j++) {
			int temp = 1;
			for (int k=0; k<4; k++) temp *= grid[i+k][j];
			if(temp>result) result = temp;
		}
	// Diagonal
	for (int i=0; i<20-4; i++) 
		for (int j=0; j<20-4; j++) {
			// Diagonal down
			int temp = 1;
			for (int k=0; k<4; k++) temp *= grid[i+k][j+k];
			if(temp>result) result = temp;
			// Diagonal up
			temp = 1;
			for (int k=0; k<4; k++) temp *= grid[i+k][j+3-k];
			if(temp>result) result = temp;
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
