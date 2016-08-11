/*************************************************************************
	> File Name: friend1.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 17 Jun 2015 02:29:51 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	public:
		Piont(int x = 0, int y = 0)
			:ix_(x),iy_(y)
		{}
		void display()
		{
			std:: << "(" << ix_ << "," << iy_ << ")" <<std::endl;
		}
	private:
		int ix_, iy_;
		friend float line(Point & p1, Point & p2);
};

float line(Point & p1, Point & p2)
{
	
}


