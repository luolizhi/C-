/*************************************************************************
  > File Name: date.cc
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Thu 25 Jun 2015 05:35:14 PM CST
 ************************************************************************/

#include<iostream>
#include<iomanip>// 为了输出两位月份和日期，不够的补0
using namespace std;

class Date
{
	public:
		//构造函数
		Date(int x = 1970, int y = 1, int z = 1 )
			:year_(x),month_(y),day_(z)
		{
			std::cout << "Date()" << std::endl;	
		}

		void display()
		{
			std::cout << year_ << "." << setw(2) << setfill('0') << month_ 
				<< "." << setw(2) << setfill('0')  << day_ << std::endl;	
		}

		bool isleap_year(int y)
		{
			return((y%4 == 0 && y%100 != 0) || (y%400 == 0));
		}

		void setdate(int y, int m, int d);

		Date & operator++();

	private:
		int year_;
		int month_;
		int day_;
};


int main(void)
{
	Date d1;
	d1.display();

#if 0
	std::string line;
	while(getline(std::cin, line))
	{
		std::stringstream num;
		while(num << line)
		{
			num >> year;	
		}
	}

#endif
	while(1)
	{
		int year, month, day;
		std::cout << "input year: " ;
		std::cin >> year;
		std::cout << "input month: ";
		std::cin >> month;
		std::cout << "input day: ";
		std::cin >> day;
		d1.setdate(year,month,day);
		d1.display();
		++d1;
		d1.display();
	}
	return 0;
}



