/*************************************************************************
	> File Name: partial_sort.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 21 Jun 2015 03:12:30 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<array>

//using namespace std;

using std::array;
using std::partial_sort;
using std::cout;
using std::endl;


int main(void)
{
	std::array<int, 10> s = {5,7,4,2,8,6,1,9,0,3};
	for(int a: s)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;
	std::partial_sort(s.begin(),s.begin()+3, s.end());

	for(int a: s)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;
}
