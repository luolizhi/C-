/*************************************************************************
	> File Name: virtual_con_des.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 26 Jun 2015 03:03:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base0
{
	public:
		Base0()
		{}

		virtual void func1()
		{
			std::cout << "Base0::func1()" << std::endl;
		}
		virtual void func2()
		{
			std::cout << "Base0::func2()" << std::endl;
		}

		~Base0()
		{}
};
class Base1 : public Base0
{
public:
	Base1()
	{
		func1();
	}

	virtual void func2()
	{
		std::cout << "Base1::func2()" << std::endl;
	}

	~Base1()
	{
		func2();
	}
};

class Subclass : public Base1
{
public:
		virtual void func1()
		{
			std::cout << "Subclass::func1()" << std::endl;
		}
		virtual void func2()
		{
			std::cout << "Subclass::func2()" << std::endl;
		}
};

int main(void)
{
	Subclass sc;
}
