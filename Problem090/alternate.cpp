// Solution to Project Euler problem 90

#include <iostream>
#include <chrono>


#include <set>
#include <vector>

typedef std::pair<std::set<int>,std::set<int>> dice;


/*
gen all combos on each die
*/


void print_config(int n){
	std::cout << "(";
	for(int i=0; i<10; i++) if (n&(1<<i)) std::cout << i << ",";
	std::cout << ")" << std::endl;
}

int bitcount(int n){
	int result = 0;
	for(; n > 0; n /= 2) result += n %2;
	return result;
}

int solution(){
	int result = 0;
	for(int d1 = 0; d1 < (1 << 10); d1++){
		for(int d2 = 0; d2 <= d1; d2++){
			//if(d1 == 798 || d2 == 798) {
			//	std::cout << d1 << " : " << bitcount(d1) << " = ";
			//	print_config(d1);
			//	std::cout << d2 << " : " << bitcount(d2) << " = ";
			//	print_config(d2);
			//}
			if (bitcount(d1) == 6 && bitcount(d2) == 6){
				std::cout << d1 << " = ";
				print_config(d1);
				std::cout << d2 << " = ";
				print_config(d2);

				int d1_temp = d1;
				int d2_temp = d2;
				if((d1 & (1<<6)) || (d1 & (1<<9))) d1_temp |= (1 << 6) | (1 << 9);
				if((d2 & (1<<6)) || (d2 & (1<<9))) d2_temp |= (1 << 6) | (1 << 9);
				bool is_sol = true;
				for(int t = 1; t*t < 100 && is_sol; t++){
					int dig1 = 1 << ((t*t)%10);
					int dig2 = 1 << (t*t/10);
					is_sol &= ( ((d1_temp & dig1) == dig1) && ((d2_temp & dig2) == dig2) ) || ( ((d1_temp & dig2) == dig2) && ((d2_temp & dig1) == dig1) );
				}
				std::cout << is_sol << std::endl;
				if (is_sol) result++;
			}
		}
	}

	return result;

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
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
