// Solution to Project Euler problem 60

#include <iostream>
#include <chrono>


#include <set>
#include <map>

/*
This problem is actually mappable to the maximum clique problem.
This problem is proven NP-Hard.
Each prime is a node, every prime-pair is an edge.
A clique is a prime-pair set.

Solution:
1. Generate primes
2. Check for pairs with existing: add to adjacency graph (map->set)
3. Search for cliques on new primes with DFS-on/off of their adjacents, checking validity.
*/

bool is_prime(int n, std::set<int> *primes){
	// check if in known primes
	if(primes->find(n) != primes->end()) return true;

	// check if factor known already
	bool prime_check = true;
	for (auto it_prime=primes->begin(); it_prime!=primes->end() &&  prime_check && (*it_prime)*(*it_prime) <= n; ++it_prime)
		prime_check = n % *it_prime;
	if(!prime_check) return false;

	// generate primes until have enough to check primality
	for (int num = *(primes->rbegin()); num*num <= n; num += 2){
		prime_check = n % num;
		if(!prime_check) return false;

		bool sub_prime_check = true;
		for (auto it_prime=primes->begin(); it_prime!=primes->end() && sub_prime_check && (*it_prime)*(*it_prime) <= num; ++it_prime)
			sub_prime_check = num % *it_prime;
		if (sub_prime_check) primes->insert(num);
	}
	return true;
}

void print_graph(std::map<int,std::set<int>> graph){
	for(auto it_n = graph.begin(); it_n != graph.end(); it_n++){
		std::cout << it_n->first << " -> ";
		for(auto it_e = it_n->second.begin(); it_e != it_n->second.end(); it_e++) std::cout << *it_e << ",";
		std::cout << std::endl;
	}
}


std::set<int> max_clique(std::set<int> candidates, std::set<int> solution, std::map<int,std::set<int>> &graph, int target){
	if(candidates.empty() || (candidates.size() + solution.size() < target)){
		return solution;
	}
	int candidate = *(candidates.begin());
	candidates.erase(candidate);
	// without_solution
	std::set<int> max_solution = max_clique(candidates, solution, graph, target);
	// with soluton
	if(graph[candidate].size() >= target-1){
		bool is_valid = true;
		for(auto it = solution.begin(); it != solution.end() && is_valid; it++) 
			if(graph[*it].find(candidate) == graph[*it].end()) is_valid = false;
		if (is_valid){
			solution.insert(candidate);
			solution = max_clique(candidates, solution, graph, target);
			if(solution.size() > max_solution.size()) max_solution = solution;
		}
	}
	return max_solution;
}


int solution(){
	int target = 5;

	std::set<int> primes = {2,3};
	std::map<int,std::set<int>> graph;
	
	int prime = 5;
	while(true){
		// Update graph with new prime
		if(is_prime(prime,&primes)){
			int prime_pos = 1;
			for(int i=prime; i>0; i/=10) prime_pos *= 10;
			for(auto p = primes.begin(); p != primes.end() && *p < prime; p++){
				int p_pos = 1;
				for(int i=*p; i>0; i/=10) p_pos *= 10;
				// Build the concatenated prime pairs	
				int cat_1 = *p * prime_pos + prime;
				int cat_2 = prime * p_pos + *p;
				//std::cout << cat_1 << " " << cat_2 << std::endl;
				if(is_prime(cat_1, &primes) && is_prime(cat_2, &primes)){
					graph[prime].insert(*p);
					graph[*p].insert(prime);
				}
			}
			// Search for cliques of target size
			if(graph[prime].size() >= target-1){
				std::set<int> solution = {prime};
				solution = max_clique(graph[prime], solution, graph, target);
				// Found a solution!
				if(solution.size() >= target) {
					//std::cout << "CLIQUE: ";
					//for(auto it = solution.begin(); it != solution.end(); it++) std::cout << *it << ", ";
					//std::cout << std::endl;
					int result = 0;
					for(auto it = solution.begin(); it != solution.end(); it++) result += *it;
					return result;
				}
			}
		}
		prime += 2;
		//if(prime > 10000) break;
	}
	// print the graph
	//print_graph(graph);
	return 0;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
