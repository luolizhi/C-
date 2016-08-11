/*************************************************************************
  > File Name: point.h
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Thu 11 Jun 2015 05:33:26 PM CST
 ************************************************************************/

#ifndef __POINT_H__
#define __POINT_H__
#include<iostream>

class Point
{
	private:
		int xpos;
		int ypos;
	public:
		Point(int x, int y);
		void print();
};
#if 0
//构造函数名必须与类名完全一样
//默认的构造函数，没有参数
Point::Point()
{
	std::cout << "构造函数" << std::endl;
	xpos = 0;
	ypos = 0;
}
#endif

Point::Point(int x = 0, int y = 0):ypos(x),xpos(y)
{
	std::cout << "有参数的构造函数" << std::endl;	
}

void Point::print()
{
	std::cout << "( " << xpos << "," << ypos << ")" << std::endl;
}


#endif
