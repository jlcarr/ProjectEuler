// Solution to Project Euler problem 13

#include <iostream>
#include <chrono>


// This is just long addition

long solution(){ 
	int digits[52];
	for (int i =0; i<52; i++) digits[i] = 0;

	int input[100][50];
	FILE* fp = fopen("numbers.txt","r");
	for (int i=0; i<100; i++) 
		for(int j=0; j<50; j++) fscanf(fp, "%1d", &input[i][j]);
	fclose(fp);
	
	
	// modulo addition
	for (int i=0; i<100; i++)
		for(int j=0; j<50; j++) digits[50-1-j] += input[i][j];
	// carries
	for(int j=0; j<51; j++) {
		digits[j+1] += digits[j]/10;
		digits[j] %= 10;
	}

	//final result
	long result = 0;
	int start;
	for(start=52-1; start>=0; start--) if (digits[start] !=0 ) break;
	for(int j=start; j>start-10; j--) result = 10*result + (long)digits[j];
	return result;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
