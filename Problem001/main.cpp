// Solution to Project Euler problem 1

#include <iostream>

int solution(){
	int n = 1000;
	int sum = 0;
	for (int i=0; i<n;i++) if(!(i%3) || !(i%5)) sum += i;
	return sum;
}

int main(){
	std::cout << solution() << std::endl;
	return 0;
}
