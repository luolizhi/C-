/*************************************************************************
	> File Name: string.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 23 Jun 2015 07:37:29 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>

using std::cout;
using std::endl;


class String
{
public:
	//默认构造函数
	String()
	{
		std::cout << "String()" << std::endl;
		pstr_ = new char[1];
	}

	//带参数构造函数
	String(const char * pstr)
	{
		std::cout << "String(const char * pstr)" << std::endl;
		pstr_ = new char[strlen(pstr) + 1];
		strcpy(pstr_, pstr);
	}

	//复制构造函数
	String(const String &rhs)
	{
		std::cout << "String(const String &rhs)" << std::endl;
		pstr_ = new char[strlen(rhs.pstr_) + 1];
		strcpy(pstr_, rhs.pstr_);
	}

	//移动构造函数
	String(String &&rhs)
		:pstr_(rhs.pstr_)
	{
		std::cout << "String(cosnt String &&)" << std::endl;

		rhs.pstr_ = NULL;
	}

	//移动赋值运算符
	String & operator=(String && rhs)
	{
		cout << "String & operator=(string &&)" << endl;
		if(this != &rhs)
		{
			delete []pstr_;
			pstr_ = rhs.pstr_;
			rhs.pstr_ = NULL;
		}
		return *this;
	}

	//赋值运算符函数， 考虑自赋值
	String & operator=(const String & rhs)
	{
		std::cout << "String &operator=(const String &rhs)" << std::endl;
		if(this != &rhs)
		{
			delete []pstr_;
			pstr_ = new char[strlen(rhs.pstr_) + 1];
			strcpy(pstr_, rhs.pstr_);
		}
		return *this;
	}

	//+=
	String & operator+=(const String &rhs)
	{
		std::cout << "operator+=" << std::endl;
		int len_this = strlen(pstr_);
		int len_rhs = strlen(rhs.pstr_);
		char* tmp = new char[len_this + len_rhs + 1];
		strcpy(tmp, pstr_);
		strcat(tmp, rhs.pstr_);
		pstr_ = tmp;
		return *this;
	}


	//析构函数
	~String()
	{
		std::cout << "~String()" << std::endl;
		delete []pstr_;
	}

friend std::ostream & operator<<(std::ostream &os, const String &rhs);
private:
	char * pstr_;
};


//直接定义为普通函数即可 +
String  operator+(const String & lhs, const String & rhs)
{
	std::cout << "oparator+(const String &, const String &)" << std::endl;
	String tmp = lhs;	
	tmp += rhs;
	return tmp;
}

String operator+(const char * pstr, const String & rhs)
{
	cout << "operator+(const char *, const String &)" << endl;
	String tmp(pstr);
	tmp += rhs;
	return tmp;
}

String  operator+(const String & rhs, const char *pstr)
{
	cout << "operator+(const String &, const char *pstr)" << endl;
	String tmp(pstr);
	tmp += rhs;
	return tmp;
}

std::ostream & operator<<(std::ostream &os, const String &rhs)
{
	os << rhs.pstr_;
	return os;
}

int main(int argc, char* argv[])
{
	String s1 = "hello";
	//std::cout << s1 << std::endl;
	String s2 = "world";
	//std::cout << s2 << std::endl;
	String s3;
	//std::cout << s3 << std::endl;
	std::cout << "===============" << std::endl;
	s3 = s1 + s2;
	
	std::cout << s3 << std::endl;

	return 0;
}
