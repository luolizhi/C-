/*************************************************************************
	> File Name: student.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 05:15:27 PM CST
 ************************************************************************/

#include<iostream>
#include "student.h"
int main()
{
	//in stack 
	CStudent stu1;
	stu1.setStudentInfo("罗",99.8);
	stu1.Display();

	//in heap
	CStudent *pstu = new CStudent;
	pstu->setStudentInfo("bill",80);
	pstu->Display();
	
	std::cout << std::endl;

	(*pstu).Display();

	delete pstu;
	pstu = NULL;



	return 0;
}
