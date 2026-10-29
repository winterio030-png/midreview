// // 4. main.cpp파일에 테스트 코드를 작성합니다. 다음을 확인하여 테스트 코드를 완성해보세요. 
// // 4-1. 전처리지시자를 넣으세요. 
// // 4-2. main을 작성합니다. 
// // 4-2-1. holiday형 객체3개를 선언하고 원하는 값으로 초기화합니다. 
// // 4-2-2. holidayGroup형을 가리키는 포인터변수를 선언하고 원하는 값으로 초기화하여 동적으로 할당합니다.  
// // 4-2-3. holidayGroup형을 가리키는 포인터변수에서 addHoliday멤버함수를 호출하는데 인자를 4-2-1에서 선언한 객체를 넣습니다. 즉, addholiday멤버함수를 3번 호출합니다. 
// // 4-2-4. holidayGroup형을 가리키는 포인터변수에서 print멤버함수를 호출합니다. 
// // 4-2-5. holidayGroup형을 가리키는 포인터변수에서 동적으로 할당한 메모리를 해제합니다. 
#include <iostream>
#include "dayOfYear.h"

#include "holidayGroup.h"



int main()
{
	using namespace Gimseoyoung2630005;
	holiday s0{"christmas",{12,25}};
	holiday s1{"childrensday", {5,5}};
	holiday s2{"parentsday", {5,8}};

	holidayGroup* ptr = { new holidayGroup{"korean holiday"} };
	ptr->addHoliday(s0);
	ptr->addHoliday(s1);
	ptr->addHoliday(s2);

	ptr->print();

	delete ptr;

	return 0;
}







// // 다음은 실습시간에 다룬 dayOfYear, holiday 클래스입니다. 
// const int daysInMonth[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};    
// class dayOfYear
// {
// 	int month; 
// 	int day;  
// 	void testMonth() 
// 	{
// 		if (month < 1 || month > 12)
// 		{
// 			std::cout << "Invalid month\n";
// 			std::exit(1);
// 		}
// 	}
// 	void testDay()
// 	{
// 		if (day < 1 || day > daysInMonth[month])
// 		{
// 			std::cout << "Invalid day\n";
// 			std::exit(1);
// 		}
// 	}
// 	void updateDay()
// 	{
// 		int maxDay{daysInMonth[month]};
// 		if (day > maxDay)
// 		{
// 			day -= maxDay; month += 1;
// 			if (month > 12) month = 1;
// 		}
// 	}
// public:
// 	dayOfYear(int m = 1, int d = 1):month{m}, day{d} 
// 	{
// 		testMonth();
// 		testDay();
// 	}
// 	void input()
// 	{
// 		std::cout << "Enter month: ";
// 		std::cin >> month; testMonth();
// 		std::cout << "Enter day: ";
// 		std::cin >> day; testDay();
// 	}
// 	friend std::istream& operator>>(std::istream& is, dayOfYear& d)
// 	{
// 		std::cout << "Enter month: ";
// 		is >> d.month; d.testMonth();
// 		std::cout << "Enter day: ";
// 		is >> d.day; d.testDay();
// 		return is;            
// 	}
// 	void setMonth(int m) {month = m; testMonth();}
// 	void setDay(int d) {day = d; testDay();}
// 	void print() const
// 	{
// 		switch(month)
// 		{
// 		case 1: std::cout << "Jan. "; break;
// 		case 2: std::cout << "Feb. "; break;
// 		case 3: std::cout << "Mar. "; break;
// 		case 4: std::cout << "Apr. "; break;
// 		case 5: std::cout << "May. "; break;
// 		case 6: std::cout << "Jun. "; break;
// 		case 7: std::cout << "Jul. "; break;
// 		case 8: std::cout << "Aug. "; break;
// 		case 9: std::cout << "Sep. "; break;
// 		case 10: std::cout << "Oct. "; break;
// 		case 11: std::cout << "Nov. "; break;
// 		case 12: std::cout << "Dec. "; break;
// 		} 
// 		std::cout << day << "\n";
// 	}
// 	friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
// 	{
// 		switch(d.month)
// 		{
// 		case 1: os << "Jan. "; break;
// 		case 2: os << "Feb. "; break;
// 		case 3: os << "Mar. "; break;
// 		case 4: os << "Apr. "; break;
// 		case 5: os << "May. "; break;
// 		case 6: os << "Jun. "; break;
// 		case 7: os << "Jul. "; break;
// 		case 8: os << "Aug. "; break;
// 		case 9: os << "Sep. "; break;
// 		case 10: os << "Oct. "; break;
// 		case 11: os << "Nov. "; break;
// 		case 12: os << "Dec. "; break;
// 		} 
// 		os << d.day << "\n";
// 		return os;
// 	}
// 	int getMonth() const {return month;}
// 	int getDay() const {return day;}
// 	dayOfYear operator++() 
// 	{
// 		++day; updateDay();            
// 		return dayOfYear{month, day};
// 	}
// 	dayOfYear operator++(int)
// 	{   
// 		dayOfYear temp{month, day};
// 		day++; updateDay();   
// 		return temp;
// 	}
// 	friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
// 	{
// 		return d1.month == d2.month && d1.day == d2.day;
// 	}
// 	friend dayOfYear operator+(const dayOfYear& d1, const dayOfYear& d2)
// 	{
// 		return dayOfYear{d1.month + d2.month, d1.day + d2.day};
// 	}
// };

// class holiday
// {
// 	std::string name; 
// 	dayOfYear date;
// public:        
// 	holiday(const std::string& n = "no name yet",
// 		dayOfYear d = dayOfYear{1,1})
// 		: name{n}, date{d}
// 	{}
// 	void print() const 
// 	{
// 		std::cout << name << ": ";
// 		date.print(); 
// 	}
// 	friend std::ostream& operator<<(std::ostream& os, const holiday& h)
// 	{
// 		os << h.name << ": ";
// 		os << h.date;
// 		return os;
// 	}
// 	friend std::istream& operator>>(std::istream& is, holiday& h)
// 	{
// 		std::cout << "Enter holiday name: ";
// 		std::getline(is >> std::ws, h.name);
// 		is >> h.date; 
// 		return is;
// 	}
// 	void input()
// 	{
// 		std::cout << "Enter holiday name: ";
// 		std::getline(std::cin >> std::ws, name);
// 		date.input();
// 	}
// 	const std::string& getName() const {return name;}
// 	const dayOfYear& getDate() const { return date; }
// 	void setName(const std::string& n) {name = n;}
// 	void setDate(const dayOfYear& d) { date = d; }
// };
  