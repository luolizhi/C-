/*************************************************************************
	> File Name: template_overload.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 19 Jun 2015 02:40:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
T MAX(T x, T y);	//函数模板的声明

int MAX(int a, int b)
{
	std::cout << "普通函数" << std::endl;
	return a > b ? a : b;
}

int main(void)
{
	int ival1 = 4;
	int ival2 = 5;
	std::cout << "MAX = " << MAX(ival1,ival2) << std::endl;

	double dval1 = 3.33;
	double dval2 = 4.44;
	std::cout << "MAX = " << MAX(dval1,dval2) << std::endl;

	return 0;
}


template<typename T>
T MAX(T x, T y)
{
	std::cout << "模板函数" << std::endl;
	return x > y ? x : y;
}
