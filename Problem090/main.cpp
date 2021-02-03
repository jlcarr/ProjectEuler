// Solution to Project Euler problem 90

#include <iostream>
#include <chrono>


#include <set>
#include <vector>

typedef std::pair<std::set<int>,std::set<int>> dice;


/*
gen all combos on each die
*/

void search(dice curr, dice rem, std::set<dice> &solutions){
	// Check if still valid searching
	if (curr.first.size() + rem.first.size() < 6) return;
	if (curr.second.size() + rem.second.size() < 6) return;
	
	// If first remains, search there
	if(curr.first.size() < 6){
		int dig = *(rem.first.begin());
		rem.first.erase(dig);
		search(curr, rem, solutions);
		curr.first.insert(dig);
		search(curr, rem, solutions);	
	}
	// If second remains, search there
	else if (curr.second.size() < 6){
		int dig = *(rem.second.begin());
		rem.second.erase(dig);
		search(curr, rem, solutions);
		curr.second.insert(dig);
		search(curr, rem, solutions);
	}
	// Otherwise now check the solution as both die are loaded
	else {
		dice temp = curr;
		if(temp.first.find(6) != temp.first.end() || temp.first.find(9) != temp.first.end()){
			temp.first.insert(6);
			temp.first.insert(9);
		}
		if(temp.second.find(6) != temp.second.end() || temp.second.find(9) != temp.second.end()){
			temp.second.insert(6);
			temp.second.insert(9);
		}

		const std::set<std::pair<int,int>> targets = {{0,1},{0,4},{0,9},{1,6},{2,5},{3,6},{4,9},{6,4},{8,1}};
		bool is_sol = true;
		for(auto it = targets.begin(); it != targets.end() && is_sol; it++){
			is_sol = ((temp.first.find(it->first) != temp.first.end() && temp.second.find(it->second) != temp.second.end()) ||
				(temp.second.find(it->first) != temp.second.end() && temp.first.find(it->second) != temp.first.end()));
		}
		if(is_sol){
			//std::cout << "(";
			//for(auto d = curr.first.begin(); d != curr.first.end(); d++) std::cout << *d << ",";
			//std::cout << "), (";
			//for(auto d = curr.second.begin(); d != curr.second.end(); d++) std::cout << *d << ",";
			//std::cout << ")" << std::endl;
			// It's a solution
			solutions.insert(curr);
			solutions.insert({curr.second,curr.first});
		}
	}
}


int solution(){
	std::set<dice> solutions;
	search({{},{}}, {{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9}}, solutions);
	
	/*for(auto sol = solutions.begin(); sol != solutions.end(); sol++){
		std::cout << "(";
		for(auto d = sol.first.begin(); d != sol.first.end(); d++) std::cout << *d << ",";
		std::cout << "), (";
		for(auto d = sol.second.begin(); d != sol.second.end(); d++) std::cout << *d << ",";
		std::cout << ")" << std::endl;
	}*/

	//std::cout << "Finaly result: " << std::endl;
	//for(auto it = solutions.lower_bound(2); it != solutions.end() && it->first <= target; it++) std::cout << it->first << " : " << it->second << std::endl;
	//std::cout << std::endl;

	return solutions.size()/2;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
