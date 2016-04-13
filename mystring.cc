/*************************************************************************
  > File Name: mystring.cc
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Wed 17 Jun 2015 09:18:55 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include"mystring.h"
using namespace std;
#if 0
class String
{
	public:
	private:
		char *pstr_;
};
#endif

//默认构造函数
String::String()
{
	std::cout << "String()" << std::endl;
	pstr_  = new char[1];//new 已经初始化了
}
String::String(const char *str)//有参构造函数
{
	std::cout << "String(const char * str)" << std::endl;
	pstr_ = new char[strlen(str)+1];
	strcpy(pstr_, str);
}
String::String(const String & rhs)	//复制构造，考虑自复制情况？
{
	std::cout << "String(const String & rhs)" << std::endl;
	pstr_ = new char[strlen(rhs.pstr_) + 1];
	strcpy(pstr_, rhs.pstr_);
}
String::~String()	//析构函数
{
	std::cout << "~String()" << std::endl;
	delete []pstr_;
}

String & String::operator=(const String & rhs)//赋值运算符的两种情况,考虑自赋值情况
{
	std::cout << "String & operator=(const String & rhs)" << std::endl;
	if(this == &rhs)
		return *this;
	delete []pstr_;
	pstr_ = new char[strlen(rhs.pstr_) + 1];
	strcpy(pstr_, rhs.pstr_);
	return *this;
}
String & String::operator=(const char *str)
{
#if 0
	std::cout << "String & operator=(const char *str)" << std::endl;
	pstr_ = new char[strlen(str) + 1];
	strcpy(pstr_, str);
#endif
	String tmp(str);
	//this->operator=(tmp);
	*this = tmp;
	return *this;
}

String & String::operator+=(const String & rhs)	//rhs连接到pstr_后面
{
	std::cout << "operator+=(const String & rhs)" << std::endl;
	int len = strlen(rhs.pstr_) + strlen(pstr_);
	pstr_ = (char *)realloc(pstr_, len + 1);
	strcat(pstr_, rhs.pstr_);
	return *this;
}
String & String::operator+=(const char * str)	//str连接到pstr_后面
{
#if 0
	std::cout << "operator+=(const char * str)" << std::endl;
	int len = strlen(str) + strlen(pstr_);
	pstr_ = (char *)realloc(pstr_, len + 1);
	strcat(pstr_, str);
#endif

	String tmp(str);
	*this += tmp;
	return *this;
}

//下标运算符，非常量，可以修改值
char & String::operator[](std::size_t index)
{
	int len = strlen(pstr_);
	static char nullchar = '\0';
	if(index > 0 && index < len)
		return pstr_[index];
	else
	{
		std::cout << "wrong index!" << std::endl;
		return nullchar;
	}
}

//常量对象取下标，不能为其赋值
const char & String::operator[](std::size_t index) const
{
	int len = strlen(pstr_);
	static char nullchar = '\0';
	if(index > 0 && index < len)
		return pstr_[index];
	else
	{
		std::cout << "wrong index!" << std::endl;
		return nullchar;
	}
}

//字符串容量
std::size_t String::size() const
{
	return strlen(pstr_);
}

//转换成c类型字符串，以'\0'结尾
const char* String::c_str() const
{
	int len = strlen(pstr_);

	pstr_[len + 1] = '\0';
	return pstr_;
}

//不懂？打印出字符串？
void String::debug()	//怎么显示打印是哪个对象的内容？
{
	std::cout << pstr_ << std::endl;	
}

//+运算符的重载，用+=解决
String operator+(const String & s1, const String & s2)
{
	std::cout << "operator+(const String & s1,const String & s2)" << std::endl;
	String ret_str = s1.pstr_;
	ret_str += s2.pstr_;
	return ret_str;
}

String operator+(const String & s, const char * str)
{
	std::cout << "operator+(String, char *)" << std::endl;
	String temp(str);
	return (s + temp);	//直接调用上面的(+)函数

}

String operator+(const char * str, const String & s)
{
	std::cout << "operator+( char *, String)" << std::endl;
	String temp(str);
	return (s + temp);	//直接调用上面的(+)函数
}

bool operator==(const String & lstr, const String & rstr)
{
	std::cout << "==" << std::endl;
	if(strcmp(lstr.pstr_, rstr.pstr_) == 0)
		return true;
	else
		return false;
}

bool operator!=(const String & lstr, const String & rstr)
{
	std::cout << "!=" << std::endl;
	return !(lstr == rstr);
}

bool operator<(const String & lstr, const String & rstr)
{
	std::cout << "<" << std::endl;
	if(strcmp(lstr.pstr_, rstr.pstr_) < 0)
		return true;
	else
		return false;
}

bool operator>(const String & lstr, const String & rstr)
{
	std::cout << ">" << std::endl;
	if(strcmp(lstr.pstr_, rstr.pstr_) > 0)
		return true;
	else
		return false;
}
bool operator<=(const String & lstr, const String & rstr)
{
	std::cout << "<=" << std::endl;
	if(strcmp(lstr.pstr_, rstr.pstr_) <= 0)
		return true;
	else
		return false;
}

bool operator>=(const String & lstr, const String & rstr)
{
	std::cout << ">=" << std::endl;
	if(strcmp(lstr.pstr_, rstr.pstr_) >= 0)
		return true;
	else
		return false;
}

std::ostream & operator<<(std::ostream & os, const String &s)
{
	os << s.pstr_ << " ";
	return os;
}
std::istream & operator>>(std::istream & is, String & s)
{
	is >> s.pstr_;
	return is;		//貌似有坑, 目前不能输入空格
}


//测试时每个函数调用都打印了信息
int main(void)
{
	String s1("hellohehe");
	s1.debug();
	std::cout << "s1.size = " << s1.size() << std::endl;//打印有点问题
	std::cout << "s1.c_str = " << s1.c_str() << std::endl;
	std::cout << s1;
	std::cout << std::endl;
	String s2("world");
	s2.debug();
	if(s1 > s2)
		std::cout << "s1 > s2" << std::endl;

	s1 = s2;
	s1.debug();
	String s3(s1);
	s3.debug();

	String s4 = s2 + s3;
	s4.debug();
#if 0
	String s5;
	std::cout << s5 << std::endl;
	std::cin >> s5;
	std::cout << s5 << std::endl;
#endif
	
	return 0;
}



