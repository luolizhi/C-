/*************************************************************************
	> File Name: student.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 05:03:22 PM CST
 ************************************************************************/

#ifndef __CSTUDENT_H__
#define __CSTUDENT_H__

#include<iostream>
#include<string.h>

class CStudent
{
private:
	char student_name_[20];
	float student_score_;
protected:

public:
	void setStudentInfo(char *name, float score);
	void Display();
};

void CStudent::setStudentInfo(char* name, float score)
{
	strcpy(CStudent::student_name_, name);
	CStudent::student_score_ = score;
}

void CStudent::Display()
{
	std::cout << "student_name: " << CStudent::student_name_ << std::endl;
	std::cout << "student_score: " << CStudent::student_score_ << std::endl;
}

#endif
