// Solution to Project Euler problem 54

#include <iostream>
#include <chrono>

#include <fstream>
#include <string>
#include <map>

/*
This is just file/data processing logic

*/

int hand_value(char suits[5], int values[5]){
	// check flush
	bool is_flush = true;
	for(int i=1; i<5; i++) is_flush = is_flush && suits[0] == suits[i];
	// check straight
	std::map<int,int> value_counts;
	for(int i=0; i<5; i++) value_counts[values[i]]++;
	bool is_straight = value_counts.size() == 5 && value_counts.rbegin()->first - value_counts.begin()->first == 5-1;
	
	// check of kinds
	bool is_four = false;
	bool is_trip = false;
	int dubs = 0;
	for(auto it =  value_counts.begin(); it != value_counts.end(); it++){
		if(it->second == 4) is_four = true;
		if(it->second == 3) is_trip = true;
		if(it->second == 2) dubs++;
	}

	// Printing
	//for(int i=0; i<5; i++) std::cout << values[i] << suits[i] << " "; 
	//std::cout << " flush=" << is_flush << " straight=" << is_straight << " 4=" << is_four << " 3=" << is_trip << " 2=" << dubs << std::endl;

	// Straight flush
	if(is_flush && is_straight) return 8*15 + value_counts.rbegin()->first;
	// 4-of-a-kind
	if(is_four) return 7*15 + value_counts.rbegin()->first;
	// Full house
	if(is_trip && dubs) return 6*15 + value_counts.rbegin()->first;
	// Flush
	if(is_flush) return 5*15 + value_counts.rbegin()->first;
	// Straight	
	if(is_straight) return 4*15 + value_counts.rbegin()->first;
	// 3-of-a-kind
	if(is_trip){ 
		int val = 0;
		for(auto it = value_counts.begin(); it != value_counts.end(); it++) if(it->second == 3 && it->first>val) val = it->first;
		return 3*15 + val;
	}
	// 2 pairs
	if(dubs == 2) {
		int val = 0;
		for(auto it = value_counts.begin(); it != value_counts.end(); it++) if(it->second == 2 && it->first>val) val = it->first;
		return 2*15 + val;
	}
	// 1 pair
	if(dubs){
		int val = 0;
		for(auto it = value_counts.begin(); it != value_counts.end(); it++) if(it->second == 2 && it->first>val) val = it->first;
		return 1*15 + val;
	}

	return value_counts.rbegin()->first;
}


int solution(){ 
	std::ifstream file("p054_poker.txt", std::ios::in);
	char suits[2][5];
	int values[2][5];
	
	int result = 0;
	while(!file.eof()){
		for(int player=0; player<2; player++){
			for(int i=0; i<5; i++){
				char val_c = file.get();
				char suit = file.get();
				if(!file.eof())file.get();
				
				int val = (int)val_c-'0';
				if(val_c == 'T') val = 10;
				if(val_c == 'J') val = 11;
				if(val_c == 'Q') val = 12;
				if(val_c == 'K') val = 13;
				if(val_c == 'A') val = 14;
				
				suits[player][i] = suit;
				values[player][i] = val;
			}
		}
		int p1_value = hand_value(suits[0],values[0]);
		int p2_value = hand_value(suits[1],values[1]);
		//std::cout << "p1=" << p1_value << " vs. p2=" << p2_value << std::endl;
		if(p1_value > p2_value) result++;
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
