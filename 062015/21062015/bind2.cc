/*************************************************************************
	> File Name: bind2.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 23 Jun 2015 10:55:05 AM CST
 ************************************************************************/

#include<iostream>
#include<functional>

using std::cout;
using std::endl;
using std::bind;

void f(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
}

int g(int n1)
{
	return n1;
}

struct Foo
{
	void print_sum(int n1, int n2)
	{
		std::cout << n1 + n2 << endl;
	}

	int data = 10;
};


int main()
{
	using namespace std::placeholders;
	int n = 7;
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001);


	return 0;
}
