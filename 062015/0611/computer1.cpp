/*************************************************************************
	> File Name: computer1.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 03:49:31 PM CST
 ************************************************************************/

#include<iostream>
#include"computer1.h"
#include<string.h>

void Computer::setpBrand(char* brand)
{	
	strcpy(Computer::pBrand_, brand);
}
void Computer::setfPrice(float price)
{
	Computer::fPrice_ = price;
}
void Computer::print()
{
	std::cout << "Brand " << Computer::pBrand_ << std::endl;
	std::cout << "Price " << Computer::fPrice_ << std::endl;
}

int main(int argc, char* argv[])
{
	Computer pc1;
	pc1.setpBrand("lenovo");
	pc1.setfPrice(4999);
	pc1.print();
	return 0;
}
