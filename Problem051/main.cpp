// Solution to Project Euler problem 51

#include <iostream>
#include <chrono>

#include <set>
#include <map>
#include <math.h>

/* 
loop up number of digits
generate primes needed
generate masks, and loop over members matching
each mask maps to a map of remaining digits to count

once target is found stop
*/


void gen_primes(long cap, std::set<long> *primes){
	for (long num = *(primes->rbegin()); num < cap; num += 2){
		bool prime_check = true;
		for (auto it_prime=primes->begin(); it_prime!=primes->end() && prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime) 
			prime_check = num % *it_prime;
		if (prime_check) primes->insert(num);
	}
}


long solution(){ 
	int target = 8;
	int digs = 2;
	long cap = 100;
	std::set<long> primes = {2,3};
	std::map<unsigned int,std::map<long,int>> mask_families;

	while(true){
		// gen primes and start fresh
		gen_primes(cap, &primes);
		mask_families.clear();
		// gen masks using binary
		for(unsigned int mask = 1; mask < (unsigned int)(1 << digs); mask++){
			for(auto it_prime = primes.lower_bound(cap/10); it_prime != primes.end(); ++it_prime){
				unsigned int temp_mask = mask;
				long temp_prime = *it_prime;
				long temp_remaining = 0;
				long temp_remaining_pos = 1;
				int star_dig = -1;
				bool matches = true;
				for(int i=0; i<digs; i++){
					long temp_dig = temp_prime%10;
					if(temp_mask%2){
						if(star_dig == -1) star_dig = temp_dig;
						matches = matches && (star_dig == temp_dig);
					}
					else temp_remaining += temp_remaining_pos * temp_dig;
					temp_remaining_pos *= 10;
					temp_prime /= 10;
					temp_mask /= 2;
				}
				if(matches){
					//std::cout << "mask = " << mask << " value = " << (*it_prime) << std::endl;
					mask_families[mask][temp_remaining]++;
				}
			}
		}
	
		// Check family sizes
		for(auto it_masks = mask_families.begin(); it_masks != mask_families.end(); it_masks++){
			//std::cout << it_masks->first << " = ";
			for(auto mask_member = it_masks->second.begin(); mask_member != it_masks->second.end(); mask_member++){
				//std::cout << mask_member->first << ":" << mask_member->second << " ";
				if (mask_member->second == target) {
					// recover inv-mask
					long mask_val = 0;
					long mask_pos = 1;
					unsigned int temp_mask = it_masks->first;
					for(int i=0; i<digs; i++){
						if(temp_mask%2) mask_val += mask_pos;
						temp_mask /= 2;
						mask_pos *= 10;
					}
					//std::cout << std::endl;
					//std::cout << "FOUND " << it_masks->first << " : " << mask_member->first << std::endl;
					//std::cout << "FOUND " << mask_val << " : " << mask_member->first << std::endl;
					for(long d = 0; d<=9; d++){
						long sol = mask_member->first + d * mask_val;
						if(sol < cap/10) continue;
						if (primes.find(sol) != primes.end()) return sol;
					}
				}
			} 
			//std::cout << std::endl; 
		}
		cap *= 10;
		digs++;
	}

	/*
	for(auto it_masks = mask_families.begin(); it_masks != mask_families.end(); it_masks++){
		std::cout << it_masks->first << " = ";
		for(auto mask_member = it_masks->second.begin(); mask_member != it_masks->second.end(); mask_member++) std::cout << mask_member->first << ":" << mask_member->second << " ";
		std::cout << std::endl; 
	}
	*/

	return 0;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
