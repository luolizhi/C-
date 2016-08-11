/*************************************************************************
	> File Name: bind.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 23 Jun 2015 10:15:25 AM CST
 ************************************************************************/

#include<iostream>
#include<functional>

using std::cout;
using std::endl;
using std::bind;

int Func(int x, int y);
auto bind1 = std::bind(Func, a, 10, std::placeholders::_1);
bind1(20);

class A
{
public:
	int Func(int x, int y);
};

int main(void)
{
	A a;
	auto bf2 = std::bind(&A::Func, std::placeholders::_1, std::placeholders::_2);
	bf2(10, 20);
}

