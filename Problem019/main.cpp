// Solution to Project Euler problem 19

#include <iostream>
#include <chrono>

/*
I believe a closed-form solution is possible using some calendar
with a lot of floor functions. But maybe not...
*/


int solution(){
	const int month_map[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int day = 1;
	int month = 1;
	int year = 1900;
	int weekday = 0;	

	int count = 0;
	while (year <=2000){
		//std::cout << year << "/" << month << "/" << day << " " << weekday << std::endl;
		// Check if in range
		if (year >= 1901){
			// Check if matches condition
			if(weekday==6 && day==1) count++;
		}
		// increment day
		day++;
		// rollover month?
		int month_len = month_map[month-1];
		if (month == 2 && ((!(year%4) && (year%100)) || !(year%400))) month_len++;
		if (day>month_len) month++;
		// rollover day?
		day = day%(month_len+1) + (day>month_len);
		// rollover year?
		if (month > 12) year++;
		// rollover month?
		month = month%(12+1) + (month>12);
		// rollover weekday
		weekday = (++weekday)%7;
	}
	return count;
}

int main(){
	auto t_start = std::chrono::high_resolution_clock::now();
	std::cout << solution() << std::endl;
	auto t_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration<double, std::milli>( t_end - t_start ).count() << std::endl;
	return 0;
}
