// Solution to Project Euler problem 59

#include <iostream>
#include <chrono>

#include <fstream>
#include <string>
#include <vector>

/*
brute force the key:
26*26*26 = 17,576
Then search for top 10 most common english words
keep score

*/


int solution(){ 
	std::vector<std::string> most_common = {"the","be","to","of","and","in","that","have"};
	std::ifstream file("p059_cipher.txt", std::ios::in);
	std::vector<int> cipher;

	// read file
	std::string temp;
	char c;
	while(!file.eof()){
		c = file.get();
		if(c < '0' || c > '9'){
			cipher.push_back(std::stoi(temp));
			temp = "";
			continue;
		}
		temp += c;
	}

	//for(auto it = cipher.begin(); it != cipher.end(); it++) std::cout << *it << std::endl;

	// brute force key
	int max_count = 0;
	std::vector<int> max_key;
	std::string max_text;
	std::vector<int> key = {'a','a','a'};
	for(int k0='a'; k0 <= 'z'; k0++){
		key[0] = k0;
		for(int k1='a'; k1 <= 'z'; k1++){
			key[1] = k1;
			for(int k2='a'; k2 <= 'z'; k2++){
				key[2] = k2;
				// decode
				std::string plaintext;
				for(int i=0; i<cipher.size(); i++) plaintext.push_back(key[i%3] ^ (char) cipher[i]);
				// Heuristic based on common english words
				int count = 0;
				for(auto word = most_common.begin(); word != most_common.end(); word++) if(plaintext.find(*word) != std::string::npos) count += word->length();
				if(count > max_count){
					max_count = count;
					max_key = key;
					max_text = plaintext;
					//std::cout << plaintext << std::endl;
					//std::cout << "MAX NOW: " << count << std::endl;
				}
			}
		}
	}

	// return sum
	int result = 0;
	for(auto c = max_text.cbegin(); c != max_text.cend(); c++) result += (int)*c;
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
