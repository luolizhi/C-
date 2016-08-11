/*************************************************************************
	> File Name: iterator.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 09:16:32 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
	std::string s("hello world");
	
	if(s.begin() != s.end())
	{
		auto it = s.begin();
		*it = toupper(*it);
	}
	std::cout << s << std::endl;
	return 0;
}
