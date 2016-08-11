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

void Date::setdate(int y, int m, int d)
{
	if(y < 1)
	{
		std::cout << "wrong year" << std::endl;
		return ;
	}
	switch(m)
	{
		case(1):
			if(d > 31 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;

		case(2):
			//如果是闰年
			if((y%4 == 0 && y%100 != 0) || (y%400 == 0))
		{
			if(d > 29 || d < 1)
			{
				std::cout << "wrong days" << std::endl;
				return ;
			}
		}
			else
			{
				if(d > 28 || d < 1)
				{
					std::cout << "wrong days" << std::endl;
					return ;
				}
			}
			break;

		case(3):
			if(d > 31 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(4):
			if(d > 30 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(5):
			if(d > 31 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(6):
			if(d > 30 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(7):
			if(d > 31 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(8):
			if(d > 31 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(9):
			if(d > 30 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(10):
			if(d > 31 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(11):
			if(d > 30 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;
		case(12):
			if(d > 31 || d < 1)
		{
			std::cout << "wrong days" << std::endl;
			return ;
		}
			break;

		default:
			std::cout << "wrong month" << std::endl;
			return ;

	}
	year_ = y;
	month_ = m;
	day_ = d;
}
Date & Date::operator++()
{
	if(month_  == 2)
	{
		if(isleap_year(year_))
		{
			if(++day_ > 29)
			{
				++month_; 
				day_ = 1;
			}
		}
		else
		{
			if(++day_ > 28)
			{
				++month_; 
				day_ = 1;
			}
		}
	}
	else if(month_ == 4 || month_ == 6 || month_ == 9 ||  month_ == 11 )
	{
		if(++day_ > 30)
		{
			++month_; 
			day_ = 1;
		}
	}
	else if(month_ == 12)
	{
		if(++day_ > 31)
		{
			++year_;
			month_ = 1;
			day_ =1;
		}
	}
	else
	{
		if(++day_ > 31)
		{
			++month_; 
			day_ = 1;
		}

	}
}


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
