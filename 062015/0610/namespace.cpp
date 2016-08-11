/*************************************************************************
  > File Name: namespace.cpp
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Wed 10 Jun 2015 05:34:59 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

extern int num ;	//外部变量
int num = 0;
namespace B
{
	int num = 2;
}

namespace A 
{
	int num = 11;
	void dispA()
	{
		int num =3;
		std::cout << "dispA函数中的num： " << num << std::endl;
		std::cout << "A中的num: " << A::num << std::endl;
		std::cout << "B中的num: " << B::num << std::endl;
		std::cout << "外部的num: " << ::num << std::endl;
	}
	
}

namespace B
{
	void dispB()
	{
		A::dispA();
	}
}

int main()
{
	B::dispB();
	A::dispA();
	return 0;
	
}	
	
void fun()
{
	std::cout << "hello" << std::endl;
}




/*
	std::cout << "extern num = " << ::num << std::endl;
	std::cout << "namespace B num = " << B::num << std::endl;
	std::cout << "namespace A num = " << A::num << std::endl;
 *
 */



#if 0
namespace A			//创建名称空间A
{
	void displayA()
	{
		std::cout << "This is A" << std::endl;
	}
}

namespace B
{
	//创建命名空间B
	void displayB()
	{
		std::cout << "This is B" << std::endl;
		A::displayA();

	}

}

int main(int argc, char* argv[])
{

	std::cout << "hello world!" << std::endl;
	A::displayA();
	B::displayB();
	return 0;
}
#endif
