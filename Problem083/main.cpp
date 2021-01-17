// Solution to Project Euler problem 83

#include <iostream>
#include <chrono>

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

/*
Similar to 82, but now we're going full Dijkstra with a priority queue

*/

int solution(){ 
	int n = 80;
	//int n = 5;
	//std::ifstream file("test_matrix.txt", std::ios::in);
	std::ifstream file("p083_matrix.txt", std::ios::in);
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
	
	// Djikstra
	// search queue
	std::set<std::vector<int>> search_queue;
	search_queue.insert({grid[0][0], 0, 0});

	std::set<std::vector<int>> done;
	
	// Already searched
	std::map<std::vector<int>,int> known = {{{0,0}, grid[0][0]}};

	while(!search_queue.empty()){
		std::vector<int> current = *(search_queue.begin());
		search_queue.erase(current);
		int score = current[0];
		int curr_i = current[1];
		int curr_j = current[2];

		//std::cout << "(" << curr_i << "," << curr_j << ") = " << score << std::endl;

		for(int move = 0; move < 4; move++){
			int i = curr_i + ( (move%2) ? 0 : (1-move) );
			int j = curr_j + ( (move%2) ? (move-2) : 0 );
			if(i < 0 || j < 0 || i >= n || j >= n) continue;
			if(known.find({i,j}) != known.end()){
				if(known[{i,j}] > grid[i][j] + score) {
					search_queue.erase({known[{i,j}], i, j});
					search_queue.insert({grid[i][j] + score, i, j});
					known[{i,j}] = grid[i][j] + score;
				}
			}
			else{
				search_queue.insert({grid[i][j] + score, i, j});
				known[{i,j}] = grid[i][j] + score;
			}
			//std::cout << "check (" << i << "," << j << ") -> " << known[{i,j}] << std::endl;
		}
	}

	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++) std::cout << known[{i,j}] << ", ";
		std::cout << std::endl;
	}
	*/

	return known[{n-1,n-1}];
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
