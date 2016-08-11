/*************************************************************************
	> File Name: point3.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 09:38:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class point
{
	private:
		int xpos;
		int ypos;
	public:
		point(int x = 0, int y = 0):xpos(x),ypos(y)
		{
			std::cout << "调用构造函数" << std::endl;
		}
		point(const point& p):xpos(p.xpos),ypos(p.ypos)
		{
			std::cout << "调用复制构造函数" << std::endl;
		}
		void print()
		{
			std::cout << "xpos : " << xpos << ",ypos : " << ypos << std::endl;
		}
};

int main()
{
	point pt1(2,3);
	pt1.print();

	point pt2 = pt1;
	pt2.print();

	point pt3(pt2);
	pt3.print();

	return 0;
}
