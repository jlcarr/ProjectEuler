// Solution to Project Euler problem 91

#include <iostream>
#include <chrono>


#include <set>
#include <vector>


/*
right angle means, slope at difference is negative reciprocal

*/

// Get gcd via euclid's
int gcd(int a, int b){
	if (!a || !b) return a?a:b;
	int gcd = a;
	int extra = b;
	while (extra){
		int temp = extra;
		extra = gcd % extra;
		gcd = temp;
	}
	return gcd;
}


int solution(){
	int target = 50;

	// start with all the right-angles on the origin
	int result = target*target;
	// then search all other locations for the right-angle
	for (int x1=0; x1<=target; x1++){
		for(int y1=1; y1<=target; y1++){
			int f = gcd(x1,y1);
			int x_slope = y1 / f;
			int y_slope = x1 / f;

			if(x1){
				int n_x = (target-x1)/x_slope;
				int n_y = y1/y_slope;
				int n_max = n_x<n_y ? n_x : n_y;
				//std::cout << x1 << "," << y1 << "," << f << " = " << n_x << "," << n_y << "," << n_max << std::endl;
				result += n_max*2; // *2 for symmetry
			}
			else{
				// right angle on axis, all options open
				result += target*2;
			}
		}
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
