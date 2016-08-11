/*************************************************************************
	> File Name: reference.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 10 Jun 2015 08:54:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main(int argc, char** argv)
{
	int x = 10;
	int y = 20;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	swap(&x,&y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;


#if 0
	int a = 10;
	int &refa = a;
	cout << "a = " <<a << endl;
	refa = 20;
	cout << "a = " <<a << endl;
	cout << "refa = " << refa << endl;
	return 0;
#endif
}
