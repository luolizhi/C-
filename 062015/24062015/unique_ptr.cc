/*************************************************************************
	> File Name: unique_ptr.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 24 Jun 2015 10:58:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<memory>
#include<vector>

std::unique_ptr<int> getVal()
{
	std::unique_ptr<int> up(new int(66));
	return up;//返回的是一个对象，就是一个右值
}

int main(void)
{
	std::unique_ptr<int> ap(new int(99));

	std::unique_ptr<int> two;

	std::cout << "*ap = " << *ap << std::endl;
	std::cout << "ap.get() = "
			  << reinterpret_cast<long>(ap.get()) << std::endl << std::endl;

	std::unique_ptr<int> up = getVal();
	std::cout << "*up = " << *up << std::endl;

	return 0;

}
