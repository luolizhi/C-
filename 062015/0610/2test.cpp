/*************************************************************************
	> File Name: 2test.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 10 Jun 2015 10:23:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int ival = 42;
	int &r1 = ival;
	const int &r2 = ival;
	std::cout << r2 << std::endl;
	r1 = 10;
	
	std::cout << r2 << std::endl;
	return 0;
}
