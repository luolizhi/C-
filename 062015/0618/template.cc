/*************************************************************************
	> File Name: template.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 18 Jun 2015 08:23:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
	if(v1 < v2)	return -1;
	if(v2 < v1)	return 1;
	return 0;
}

int main(void)
{
	std::cout << compare(1,3) << std::endl;
	std::cout << compare(1.3,0.3) << std::endl;
	std::cout << compare('a','a') << std::endl;

	return 0;
}
