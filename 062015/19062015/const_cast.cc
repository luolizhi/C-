/*************************************************************************
	> File Name: const_cast.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 19 Jun 2015 09:55:19 AM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int func(int &a)
{
	++a;
	int *pa = &a;
	printf("pa = %x\n", pa);
	return a;
}

int main(void)
{

	const int ival = 10;
	//int ret = func(ival);	//int &a = ival;
	//const_cast作用是去常量属性
	int ret = func(const_cast<int &>(ival));
	std::cout << "ret = " << ret << std::endl;
	std::cout << "ival = " << ival << std::endl;
	printf("&ival = %x\n", &ival);
	return 0;
}
