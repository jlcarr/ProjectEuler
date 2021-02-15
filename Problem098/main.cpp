// Solution to Project Euler problem 98

#include <iostream>
#include <chrono>


#include <fstream>
#include<string>

#include <list>
#include <set>
#include <map>
#include <vector>

#include <algorithm>
#include <math.h>

/*
1. Get longest word length
2. Generate all squares possible
3. Filter squares by if they have a permutation pair
4. Convert to masks
5. Filter words by if they have a permutation pair
6. 

*/


int solution(){
	std::ifstream file("p098_words.txt", std::ios::in);
	//std::ifstream file("test_input.txt", std::ios::in);
	std::set<std::string> words;
	std::map<std::string, std::set<std::string>> perm_sets;

	// Parse the dataset
	char c;
	std::string word = "";
	while(!file.eof()){
		c = file.get();
		if(c == '"') continue;
		if(c == ','){
			//words.insert(word);
			std::string sorted_word = word;
			std::sort(sorted_word.begin(), sorted_word.end());
			perm_sets[sorted_word].insert(word);
			word = "";
		}
		else word += c;
	}
	file.close();

	// Filter down to ones that can have permutation pairs
	for(auto perm_it=perm_sets.begin(); perm_it!=perm_sets.end(); perm_it++) 
		if(perm_it->second.size() >= 2) words.insert(perm_it->second.begin(), perm_it->second.end());
	// Fill perm-types
	std::map<std::vector<int>, std::set<std::string>> string_masks;
	for(auto it=words.begin(); it!=words.end(); it++){
		std::map<char,int> char_index;
		std::vector<int> mask;
		for(auto c_it=it->begin(); c_it!=it->end(); c_it++){
			if(char_index.find(*c_it) == char_index.end()){
				char_index[*c_it] = mask.size();
				mask.push_back(0);
			}
			mask[char_index[*c_it]]++;
		}
		string_masks[mask].insert(*it);
		//std::cout << *it << " : ";
		//for(auto mask_it=mask.begin(); mask_it!=mask.end(); mask_it++) std::cout << *mask_it << ", ";
		//std::cout << std::endl;
	}

	// Do everything from before but for square numbers
	

	// max length for our square search
	int max_perm_len = 0;
	for(auto it=words.begin(); it!=words.end(); it++) if(it->size() > max_perm_len) max_perm_len = it->size() ;

	// Perform the square search
	std::map<std::string, std::set<int>> sq_perm_sets;
	long long base = 1;
	for(int i=0; i<max_perm_len; i++){
		base *= 10;
		long long  min_val = (long long)sqrt(base);
		long long  max_val = (long long)sqrt(10*base);
		for(long long n=min_val; n<max_val; n++){
			std::string num = std::to_string(n*n);
			std::sort(num.begin(), num.end());
			sq_perm_sets[num].insert(n*n);
			//std::cout << num << " : " << (n*n) <<std::endl;
		}
	}
	//std::cout << "size: " << sq_perm_sets.size() << std::endl;

	// Fill perm-types
	std::set<long long> squares;
	for(auto perm_it=sq_perm_sets.begin(); perm_it!=sq_perm_sets.end(); perm_it++)
		if(perm_it->second.size() >= 2) squares.insert(perm_it->second.begin(), perm_it->second.end());
	//std::cout << "size: " << squares.size() << std::endl;


	// Perform the final search
	long long result = 0;
	for(auto sq_it=squares.begin(); sq_it!=squares.end(); sq_it++){
		// Turn the square into a mask
		std::string sq_string = std::to_string(*sq_it);
		std::map<char,int> char_index;
		std::vector<int> mask;
		for(auto c_it=sq_string.begin(); c_it!=sq_string.end(); c_it++){
			if(char_index.find(*c_it) == char_index.end()){
				char_index[*c_it] = mask.size();
				mask.push_back(0);
			}
			mask[char_index[*c_it]]++;
		}
		// now find those matching the mask
		if(string_masks.find(mask) == string_masks.end()) continue;
		for(auto string_it=string_masks[mask].begin(); string_it!=string_masks[mask].end(); string_it++){
			std::string perm = *string_it;
			// Define mapping specified
			std::map<char,long long> char_map;
			for(int i=0; i<perm.size(); i++) char_map[perm[i]] = (long long)(sq_string[i]-'0');
			//search for the other anagrams, and check if they are squares
			std::sort(perm.begin(),perm.end());
			for(auto it_word=perm_sets[perm].begin(); it_word!=perm_sets[perm].end(); it_word++){
				word = *it_word;
				if(word == *string_it || !char_map[word[0]]) continue;
				long long sq_poss = 0;
				for(auto c_it=word.begin(); c_it!=word.end(); c_it++) sq_poss = 10*sq_poss + char_map[*c_it];
				if(squares.find(sq_poss) != squares.end() && sq_poss>result){
					//std::cout << *string_it << " = " << *sq_it << "  :  " << word << " = " << sq_poss << std::endl;
					result = sq_poss;
				}
			}
		}
	}


	//for(auto it=words.begin(); it!=words.end(); it++){
	//	word = *it;
	//	std::cout << word << " : ";
	//	std::sort(word.begin(), word.end());
	//	std::cout << perm_sets[word].size() << std::endl;
	//}

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
