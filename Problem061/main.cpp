// Solution to Project Euler problem 61

#include <iostream>
#include <chrono>


#include <set>
#include <map>
#include <math.h>
#include <list>

/*
array of sets for figurate numbers
pregenerate figurate numbers in range
Perform search keeping track of figures needed
*/


std::list<int> search(int next, int final_val, std::set<int> fig_list, std::set<int> *figurate){
	if(fig_list.empty() && (next%100 == final_val/100)) return std::list<int>({next});
	int lower_bound = (next%100)*100;
	int upper_bound = (next%100+1)*100;
	//std::cout << "between " << lower_bound << " and " << upper_bound << std::endl;
	for(auto it = fig_list.rbegin(); it != fig_list.rend(); it++){
		std::set<int> temp = fig_list;
		temp.erase(*it);
		//std::cout << "For fig-" << *it << std::endl;
		//std::cout << " in " << *(figurate[*it].begin()) << " - "<< *(figurate[*it].rbegin()) << std::endl;
		for(auto val = figurate[*it-3].lower_bound(lower_bound); val != figurate[*it-3].upper_bound(upper_bound); val++){
			//std::cout << "Searching " << *val << " for fig-" << *it << std::endl;
			std::list<int> sol = search(*val, final_val, temp, figurate);
			if(!sol.empty()){
				sol.push_front(next);
				return sol;
			}
		}
	}
	return std::list<int>();
}


int solution(){
	int max_fig = 8;
	int pos = 1000;

	// pregenerate figurate numbers
	std::set<int> figurate[max_fig-3+1];
	for(int fig = 3; fig <= max_fig; fig++){
		// generate figurate numbers
		int val = 1;
		for(int i=1; val < 10*pos; val += (fig-2)*(++i - 1)+1){
			//std::cout << val << std::endl;
			if(val >= pos) figurate[fig-3].insert(val);
		}
		//std::cout << fig << "-figs : " << figurate[fig-3].size() << " from " << *(figurate[fig-3].begin()) << " to " << *(figurate[fig-3].rbegin()) << std::endl;
	}

	// search for a fig-path
	std::set<int> fig_list;
	for(int i=3; i<max_fig; i++) fig_list.insert(i);

	for(auto fig = figurate[max_fig-3].begin(); fig != figurate[max_fig-3].end(); fig++){
		//std::cout << "Search " << *fig << " for fig-" << max_fig << std::endl;
		std::list<int> sol = search(*fig, *fig, fig_list, figurate);
		if(!sol.empty()) {
			//for(auto val = sol.begin(); val != sol.end(); val++) std::cout << *val << ", ";
			//std::cout << std::endl;
			int result = 0;
			for(auto val = sol.begin(); val != sol.end(); val++) result += *val;
			return result;
		}
	}

	return 0;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
