// Solution to Project Euler problem 17

#include <iostream>
#include <chrono>

#include <string.h>


long solution(){
	// Precomputations (thank you compiler!)
	const char* less_than_20_literals[19] = {"one","two","three","four","five","six","seven","eight","nine",
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	int less_than_20[19];
	for (int i=0; i<19; i++) less_than_20[i] = (int) strlen(less_than_20_literals[i]);

	const char* tens_literals[8] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	int tens[8];
	for (int i=0; i<8; i++) tens[i] = (int) strlen(tens_literals[i]);
	
	int hundred = (int) strlen("hundred");
	int thousand = (int) strlen("thousand");
	
	int result = 0;
	int prev = 0;
	for (int n = 1; n <= 1000; n++){
		int i = n;
		// n-thousands
		if (i>=1000){
			result += less_than_20[(i/1000)%10 - 1];
			result += thousand;
		}
		i %= 1000;
		// n-hundreds
		if (i>=100){
			result += less_than_20[(i/100)%10 - 1];
			result += hundred;
		}
		i %= 100;
		// and
		if(n>i && i>0) result += 3;
		// tens
		if (i>=20){
			result += tens[(i/10)%10 - 2];
			i %= 10;
		}
		if (i>0) result += less_than_20[i - 1];
		//std::cout << n << " : " << result - prev << std::endl;
		prev =result;
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
