/*************************************************************************
	> File Name: bind_func.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 08:46:43 PM CST
 ************************************************************************/

#include<iostream>
#include <functional>
using namespace std;

class Myfun
{
	public:
		void print(int i, int j)
		{
			cout << i << "\t" << j << endl;
		}
};

int main(void)
{
	function<void(int, int)> func;
	Myfun f;
	func = bind(&Myfun::print, f, 3, std::placeholders::_1);
	func(1, 2);
	return 0;
}
