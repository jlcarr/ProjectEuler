// Solution to Project Euler problem 96

#include <iostream>
#include <chrono>


#include <fstream>
#include <string>

#include <set>
#include <map>
#include <vector>


/*
Keep track of current solution
Keep track of remaining possibilities
Apply some logic to cut down.
Apply a recursive search.

*/

std::vector<std::vector<char>> solve_sudoku(std::vector<std::vector<char>> sudoku, std::map<int,std::map<int,std::set<char>>> possibs){
	bool updated = true;
	while(updated){
		updated = false;
		for(int row=0; row<9; row++){
			for(int col=0; col<9; col++){
				if(sudoku[row][col] != '0') continue;
				// check row, col and cell
				int poss_count = possibs[row][col].size();
				for(int i=0; i<9; i++) if(i!=row) possibs[row][col].erase(sudoku[i][col]);
				for(int i=0; i<9; i++) if(i!=col) possibs[row][col].erase(sudoku[row][i]);
				for(int i=0; i<9; i++) if(i/3 + (row/3)*3 != row || i%3 + (col/3)*3 != col) possibs[row][col].erase(sudoku[i/3+(row/3)*3][i%3+(col/3)*3]);
				if(possibs[row][col].size() != poss_count) updated = true;

				//check if solution was found for value
				if (possibs[row][col].size() == 1){
					sudoku[row][col] = *(possibs[row][col].begin());
					possibs[row].erase(col);
				}

				if(sudoku[row][col] != '0') continue;


				// check if has any single-possibs
				std::set<char> single_possib = possibs[row][col];
				for(int i=0; i<9 && !single_possib.empty(); i++) if(i!=row && sudoku[i][col]=='0') 
					for(auto it=possibs[i][col].begin(); it!=possibs[i][col].end() && !single_possib.empty(); it++) 
						single_possib.erase(*it);
				for(int i=0; i<9 && !single_possib.empty(); i++) if(i!=col && sudoku[row][i]=='0') 
					for(auto it=possibs[row][i].begin(); it!=possibs[row][i].end() && !single_possib.empty(); it++) 
						single_possib.erase(*it);
				for(int i=0; i<9 && !single_possib.empty(); i++){
					int i_row = i/3 + (row/3)*3;
					int i_col = i%3 + (col/3)*3;
					if(i_row == row && i_col == col) continue;
					if(sudoku[i_row][i_col] != '0') continue;
					for(auto it=possibs[i_row][i_col].begin(); it!=possibs[i_row][i_col].end() && !single_possib.empty(); it++)
						single_possib.erase(*it);
				}

				if(single_possib.size() == 1){
					sudoku[row][col] = *(single_possib.begin());
					updated = true;
					possibs[row].erase(col);
				}

				//std::cout << row << "," << col << " : ";
				//for(auto it=possibs[row][col].begin(); it != possibs[row][col].end(); it++) std::cout << *it << ",";
				//std::cout << std::endl;
			}
		}
		//break;
	}


	// Exhausted all logic: guess and tests
	int rem_count = 0;
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) if(sudoku[i][j] == '0') rem_count++;
	//std::cout << "rem: " << rem_count << std::endl;
	//for(int row=0; row<9; row++){
		//for(int col=0; col<9; col++) std::cout << sudoku[row][col];
		//std::cout << std::endl;
	//}

	
	// Check if is still valid
	for(int row=0; row<9; row++){
		//if(possibs.find(row) == possibs.end()) continue;
		for(int col=0; col<9; col++){
			if(sudoku[row][col] == '0' && possibs[row][col].empty()) return sudoku;
		}
	}
			
	// Could make this more efficient
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			if(sudoku[row][col] != '0') continue;

			std::set<char> guesses = possibs[row][col];
			possibs[row].erase(col);

			//std::cout << row << "," << col << " : ";
			//for(auto it=guesses.begin(); it!=guesses.end(); it++) std::cout << *it << ",";
			//std::cout << std::endl;

			for(auto it=guesses.begin(); it!=guesses.end(); it++){
				//std::cout << row << "," << col << " : " << *it << std::endl;
				sudoku[row][col] = *it;
				std::vector<std::vector<char>> searched_solution = solve_sudoku(sudoku, possibs);

				//check if sol
				bool is_sol = true;
				for(int i=0; i<9; i++) for(int j=0; j<9; j++) if(searched_solution[i][j] == '0') is_sol = false;
				if(is_sol) return searched_solution;
			}
			sudoku[row][col] = '0';
			//possibs[row][col] = guesses;
			// No valid solutions exist here
			return sudoku;
		}
	}

	return sudoku;
}


int solution(){
	std::ifstream file("p096_sudoku.txt", std::ios::in);
	//std::ifstream file("test_input.txt", std::ios::in);
	//std::ifstream file("test_input2.txt", std::ios::in);

	int n_puzzle = 0;
	std::vector<std::vector<char>> sudoku(9, std::vector<char>(9));
	int result = 0;

	std::string line;
	int line_number = 0;
	while(std::getline(file, line)){
		line_number %= 10;
		//std::cout << line << " : " << line_number << " : " << (line_number % 10 != 0) << std::endl;
		// perform parsing
		if(line_number++ == 0) continue;

		//std::cout << line << std::endl;
		std::vector<char> temp(line.begin(), line.end());
		sudoku[line_number-2] = temp;

		if(line_number != 10) continue;
		// Once the puzzle is completely read, solve it		

		// prepare initial values
		std::map<int,std::map<int,std::set<char>>> possibs;
		for(int row=0; row<9; row++){
			for(int col=0; col<9; col++){
				if(sudoku[row][col] == '0'){
					for(char num='1'; num<='9'; num++) possibs[row][col].insert(num);
				}
			}
		}

		//solve it!
		//std::cout << "begin solving" << std::endl;
		sudoku = solve_sudoku(sudoku, possibs);

		//std::cout << "final sol" << std::endl;
		//for(int row=0; row<9; row++){
		//	for(int col=0; col<9; col++) std::cout << sudoku[row][col];
		//	std::cout << std::endl;
		//}
		//std::cout << "done" << std::endl;

		result += 100*(sudoku[0][0]-'0') + 10*(sudoku[0][1]-'0') + 1*(sudoku[0][2]-'0');
		n_puzzle++;
	}
	file.close();

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
