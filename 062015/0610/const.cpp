/*************************************************************************
	> File Name: const.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 10 Jun 2015 08:29:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 30;
	const int *pa = &a;
	cout << "a = " << a << endl;
	//*pa = 20;	//error 
	pa = &b;
	cout << "pa = " << *pa <<endl;
	
	int * const pb = &a;
	cout << "pb(&a) = " << *pb << endl;
	*pb = 20;
	//pb = &a;	//error
	cout << "pb = " << *pb <<endl;
	return 0;

}
