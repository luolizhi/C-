/*************************************************************************
	> File Name: string.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 10 Jun 2015 09:21:32 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;

int main(int argc, char* argv[])
{
	std::string str1 = "hello";
	std::string str2("world");
	std::cout << "str1:" << str1 << std::endl;
	std::cout << "str2:" << str2 << std::endl;
	std::string str3 = str1 + str2;
	std::cout << "str3:" << str3 << std::endl;
	std::string sub1 = str3.substr(0,5);
	std::string sub2 = str3.substr(8,2);
	std::string sub3 = str3.substr(8,8);
	std::string sub4 = str3.substr(10,2);
	std::cout << "sub1:" << sub1 << std::endl;
	std::cout << "sub2:" << sub2 << std::endl;
	std::cout << "sub3:" << sub3 << std::endl;
	std::cout << "sub4:" << sub4 << std::endl;
	//遍历字符串
	int index;
	int len = str3.size();
	for(index=0;index<len;index++)
	{
		std::cout << str3[index] << std::endl;
	}

	std::string::iterator it = str3.begin();
	for(; it != str3.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}
