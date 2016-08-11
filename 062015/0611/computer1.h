/*************************************************************************
	> File Name: computer1.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 03:49:31 PM CST
 ************************************************************************/

#include<iostream>

class Computer
{
private:
	char pBrand_[20];
	float fPrice_;
public:
	void setpBrand(char* brand);
	void setfPrice(float price);
	void print();
};


