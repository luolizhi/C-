/*************************************************************************
	> File Name: point.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 05:38:57 PM CST
 ************************************************************************/

#include"point.h"
#include<string.h>
using namespace std;

int main()
{
	Point p1;
	p1.print();
	
	Point p2(2);
	p2.print();

	Point p3(3,4);
	p3.print();
	
	
	return 0;
}
