#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

class MyString
{
	public:
#if 1
		MyString();//默认构造函数
		MyString(char* str);//普通构造函数
		MyString(const MyString &rhs);//拷贝构造函数
		MyString & operator=(const MyString & rhs);//赋值函数(MyString &是返回值类型，operator=是函数名)
		~MyString();//析构函数
#endif
		void print();//打印函数
	private:
		char* pstr_;
};
#if 1
MyString::MyString()
{
	std::cout << "调用默认构造函数" << std::endl;
	pstr_ = new char[1];
	//*pstr_ = '\0';	//new 已经初始化了
}

MyString::MyString(char* str)
{
	std::cout << "调用普通构造函数" << std::endl;
	//pstr = (char*)malloc(sizeof(char)*(strlen(str) + 1));
	pstr_ = new char[strlen(str) + 1];
	strcpy(pstr_, str);
}

MyString::MyString(const MyString & rhs)
{
	std::cout << "调用拷贝构造函数" << std::endl;
	pstr_ = new char[strlen(rhs.pstr_) + 1];
	strcpy(pstr_, rhs.pstr_);
}
MyString & MyString::operator=(const MyString & rhs)
{
	std::cout << "调用赋值函数" << std::endl;
	if(this == &rhs)
		return *this;
	delete []pstr_;	//释放原有的内存资源
	pstr_  = new char[strlen(rhs.pstr_) + 1];
	strcpy(pstr_, rhs.pstr_);
	return (*this);
}

MyString::~MyString()
{
	std::cout << "调用析构函数" << std::endl;
	delete MyString::pstr_;
}

#endif

void MyString::print()
{
	if(strcmp(MyString::pstr_ ,"") != 0)
	std::cout << "MyString is: " << MyString::pstr_  <<std::endl;
}


int main(void)
{
	MyString str1;
	str1.print();
#if 1	

	MyString str2 = "hello world";
	str2.print();
	
	MyString str3 = "wangdao";
	str3.print();
	str2 = str3;
	str2.print();

	MyString str4 = str3;
	str4.print();

#endif

	return 0;
}
