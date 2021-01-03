// Solution to Project Euler problem 79

#include <iostream>
#include <chrono>

#include <fstream>
#include <map>
#include <set>
#include <list>

/*
If there is only 1 possible solution,
then the number orderings must make up a weakly connected graph
If every number can only be used one then the problem reduces down to the Hamiltonian path problem
*/


std::list<long> hamiltonian_path(std::map<long, std::set<long>> order_graph){
	std::list<long> result;
	while(true){
		// Find the final digit
		long dig;
		int empties = 0;
		for(auto v = order_graph.begin(); v != order_graph.end(); v++){
			if(v->second.size() == 0) empties++;
			if(v->second.size() == 1){
				dig = *(v->second.begin());
				break;
			}
		}
		// if done
		if (empties == order_graph.size()){
			std::set<long> search_result(result.begin(), result.end());
			for(auto v = order_graph.begin(); v != order_graph.end(); v++) 
				if(search_result.find(v->first) == search_result.end()) result.push_front(v->first);
			return result;
		}
		// Remove
		for(auto v = order_graph.begin(); v != order_graph.end(); v++) v->second.erase(dig);
		result.push_front(dig);
	}
}


long solution(){ 
	std::ifstream file("p079_keylog.txt", std::ios::in);
	//std::ifstream file("test.txt", std::ios::in);
	std::map<long, std::set<long>> order_graph;

	// read file
	long read_value;
	while(file >> read_value){
		order_graph[(read_value/100)%10].insert((read_value/10)%10);
		order_graph[(read_value/10)%10].insert(read_value%10);
	}

	/*for(auto k = order_graph.begin(); k != order_graph.end(); k++){
		std::cout << k->first << " : ";
		for(auto it = k->second.begin(); it != k->second.end(); it++) std::cout << *it << ", ";
		std::cout << std::endl;
	}*/

	std::list<long> temp_result = hamiltonian_path(order_graph);
	long result = 0;
	for(auto it = temp_result.begin(); it != temp_result.end(); it++){
		result = 10*result + *it;
		//std::cout << *it;
	}
	//std::cout << std::endl;

	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
