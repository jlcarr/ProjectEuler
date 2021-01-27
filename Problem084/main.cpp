// Solution to Project Euler problem 84

#include <iostream>
#include <chrono>

#include <algorithm>
#include <list>
#include <vector>
#include <utility>

/*

*/

int solution(){
	const int n_squares = 40;
	const int n_dice = 4;
	const int n_games = 1000;
	const int n_turns = 10000;

	// Community Chest
	std::vector<int> CC_shuffle;
	for(int i=1; i<=2; i++) CC_shuffle.push_back(i);
	while(CC_shuffle.size() < 16) CC_shuffle.push_back(0);

	// Chance
	std::vector<int> CH_shuffle;
	for(int i=1; i<=10; i++) CH_shuffle.push_back(i);
	while(CH_shuffle.size() < 16) CH_shuffle.push_back(0);
	std::random_shuffle(CH_shuffle.begin(), CH_shuffle.end());
	std::list<int> CH(CH_shuffle.begin(), CH_shuffle.end());
	
	/*
	std::cout << "CC deck: ";
	for(auto it = CC.begin(); it != CC.end(); it++) std::cout << *it << ", ";
	std::cout << std::endl;

	std::cout << "CH deck: ";
	for(auto it = CH.begin(); it != CH.end(); it++) std::cout << *it << ", ";
	std::cout << std::endl;
	*/

	std::vector<int> visits(n_squares,0);

	for(int i_game=0; i_game<n_games; i_game++){
		int position = 0;
		int doubles_count = 0;

		std::random_shuffle(CC_shuffle.begin(), CC_shuffle.end());
		std::list<int> CC(CC_shuffle.begin(), CC_shuffle.end());

		std::random_shuffle(CH_shuffle.begin(), CH_shuffle.end());
		std::list<int> CH(CH_shuffle.begin(), CH_shuffle.end());

		for(int i_turn=0; i_turn<n_turns; i_turn++){
			// roll dice
			int roll1 = 1 + rand()%n_dice;
			int roll2 = 1 + rand()%n_dice;
			if(roll1 == roll2) doubles_count++;
			else doubles_count = 0;
			position += roll1 + roll2;
			position %= n_squares;
		
			// apply specials
			// 3 doubles
			if(doubles_count >= 3){
				position = 10;
				doubles_count = 0;
			}
			// G2J
			if(position == 30) position = 10;

			// CC
			if(position == 2 || position == 17 || position == 33){
				if(CC.back() == 1) position = 0;
				else if(CC.back() == 2) position = 10;
				CC.push_front(CC.back());
				CC.pop_back();
			}

			// CH
			if(position == 7 || position == 22 || position == 36){
				if(CH.back() == 1) position = 0;
				else if(CH.back() == 2) position = 10;
				else if(CH.back() == 3) position = 11;
				else if(CH.back() == 4) position = 24;
				else if(CH.back() == 5) position = 39;
				else if(CH.back() == 6) position = 5;
				else if(CH.back() == 7 || CH.back() == 8){
					if(position == 7) position = 15;
					if(position == 36) position = 5;
					else if(position == 22) position = 25;
				}
				else if(CH.back() == 9){
					if(position == 7 || position == 36) position = 12;
					else if(position == 22) position = 28;
				}
				else if(CH.back() == 10) position -= 3; // no need to modulo
				CH.push_front(CH.back());
				CH.pop_back();
			}

			// count
			visits[position]++;
			//std::cout << "position: " << position << " (roll: " << roll << ")" << std::endl;
		}
	}

	std::vector<double> visits_percent(n_squares, 0.0);
	for(auto i_square = 0; i_square != visits.size(); i_square++) visits_percent[i_square] = 100.0 * ((double) visits[i_square]) / ((double) (n_games*n_turns));
	//for(auto i_square = 0; i_square != visits.size(); i_square++) std::cout << i_square << ": " << visits[i_square] << " : " << visits_percent[i_square] << std::endl;

	std::vector<std::pair<double,int>> sorter;
	for(auto i_square = 0; i_square != visits.size(); i_square++) sorter.push_back({visits_percent[i_square], i_square});
	std::sort(sorter.begin(), sorter.end());
	//std::cout << std::endl << "Sorted results: " << std::endl; 
	//for(auto i_pos = 0; i_pos != visits.size(); i_pos++) std::cout << sorter[i_pos].second << ": " << sorter[i_pos].first << std::endl;

	int result = 0;
	for(int i = 0; i < 3; i++) result = 100*result + sorter[sorter.size() - 1 - i].second;
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
