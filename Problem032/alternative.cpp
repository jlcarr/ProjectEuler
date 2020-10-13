// Solution to Project Euler problem 32

#include <iostream>
#include <chrono>

#include <set>
#include <list>

/*

keep ordered set of remaining digits
keep lists of result so far
check if can end

*/

int check_sol(std::list<int> l, std::list<int> r){
	std::set<int> digits = {1,2,3,4,5,6,7,8,9};
	int l_build = 0;
	for(auto i = l.begin(); i != l.end(); i++) {
		l_build = 10*l_build + *i;
		digits.erase(*i);
	}
	int r_build = 0;
	for(auto i = r.begin(); i != r.end(); i++) {
		r_build = 10*r_build + *i;
		digits.erase(*i);
	}
	int lr = l_build*r_build;
	int result = lr;
	//std::cout << l_build << " : " << r_build << std::endl;

	while(lr>0){
		int dig = lr%10;
		lr /= 10;
		if (digits.find(dig) == digits.end()) return 0;
		digits.erase(dig);
	}
	if(!digits.empty()) return 0;
	std::cout << l_build << " x " << r_build << " = " << result << std::endl;
	return result;
}

int check_partial(std::list<int> l, std::list<int> r, std::set<int> digits){
	if(!l.size() || !r.size()) return 1;
	int l_build = 0;
	for(auto i = l.begin(); i != l.end(); i++)
		l_build = 10*l_build + *i;
	int r_build = 0;
	for(auto i = r.begin(); i != r.end(); i++)
		r_build = 10*r_build + *i;
	int lr = l_build*r_build;
	int result = lr;

	int max_size = l.size()<r.size()? l.size() : r.size();
	for(int i=0; i<max_size; i++){ 
		if (digits.find(lr%10) == digits.end()) return 0;
		lr/=10;
	}

	int size = 0;
	lr = result;
	while(lr>0) {
		lr/=10;
		size++;
	}
	if (size>l.size()+r.size()) return false;
	return result;
}

int build_sol(std::list<int> l, std::list<int> r, std::set<int> digits, bool stop_l, bool stop_r){
	/*	
	for(auto l_i = l.begin(); l_i != l.end(); l_i++) std::cout << *l_i;
	std::cout << " x ";
	for(auto r_i = r.begin(); r_i != r.end(); r_i++) std::cout << *r_i;
	std::cout << " = " << check_partial(l,r,digits) << " : "<< check_sol(l,r) << std::endl;
	*/
	if(stop_l && stop_r) return 0;
	if(!check_partial(l,r,digits)) return 0;
	int result = check_sol(l,r);
	if(result) return result;

	std::set<int> l_digits;
	if(!stop_l) l_digits = digits;
	if(l.size()) l_digits.insert(0);
	std::set<int> r_digits;
	if(!stop_r) r_digits = digits;
	if(r.size()) r_digits.insert(0);
	for(auto l_dig = l_digits.begin(); l_dig != l_digits.end(); l_dig++){
		for(auto r_dig = r_digits.begin(); r_dig != r_digits.end(); r_dig++){
			if(*r_dig == *l_dig) continue;						
			std::set<int> temp_digits = digits;
			temp_digits.erase(*l_dig);
			temp_digits.erase(*r_dig);
			if(*l_dig) l.push_front(*l_dig);
			if(*r_dig) r.push_front(*r_dig);

			result += build_sol(l,r,temp_digits,!(bool)*l_dig,!(bool)*r_dig);
			
			if(*l_dig) l.pop_front();
			if(*r_dig) r.pop_front();
		}
	}

	return result;
}


int solution(){
	int n=5;
	std::set<int> digits = {1,2,3,4,5,6,7,8,9};

	std::list<int> l;
	std::list<int> r;

	//return check_partial(l, r, digits);
	return build_sol(l, r, digits, false, false)/2;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
