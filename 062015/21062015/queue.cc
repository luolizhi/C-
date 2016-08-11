/*************************************************************************
	> File Name: queue.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 23 Jun 2015 09:55:02 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>

using std::cout;
using std::endl;
using std::queue;

int main(void)
{
	int i = 0;
	queue<int> v;
	for(i = 0; i< 10; i++)
	{
		v.push(i);
		cout << v.back() << "  already in the queue" << endl;
	}
}
