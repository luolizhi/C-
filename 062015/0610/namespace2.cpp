/*************************************************************************
	> File Name: namespace2.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 10 Jun 2015 07:59:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

float float1 = 88.8f;

namespace
{
	float funnamespacefloat = 99.8f;
}

namespace ns1
{
	const int integer1 = 100;
	const double double1 = 100.5;
	float float1 = 99.9f;
	void printvalue();
	namespace inner
	{
		double innerdouble = 55.5;
	}
}

int  main(void)
{
	cout << "全局变量" << ::float1 << endl;
	cout << "匿名名称空间变量" << funnamespacefloat <<endl;
	cout << "ns1::integerl1 = " << ns1::integer1 << endl;
	cout << "ns1::double1 = " << ns1::double1 << endl;
	cout << "ns1::float1 = " << ns1::float1 << endl;
	cout << "ns1::inner::innerdouble = " << ns1::inner::innerdouble << endl;
	cout << endl;
	ns1::printvalue();
	return 0;
}

void ns1::printvalue()
{
	cout << "全局变量" << ::float1 << endl;
	cout << "匿名名称空间变量" << funnamespacefloat <<endl;
	cout << "ns1::integerl1 = " << ns1::integer1 << endl;
	cout << "ns1::double1 = " << ns1::double1 << endl;
	cout << "ns1::float1 = " << ns1::float1 << endl;
	cout << "ns1::inner::innerdouble = " << ns1::inner::innerdouble << endl;
	
}
