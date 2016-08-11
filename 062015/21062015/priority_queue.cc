/*************************************************************************
	> File Name: priority_queue.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 23 Jun 2015 10:01:22 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>

//using namespace std;

using std::cout;
using std::endl;
using std::priority_queue;

int main(void)
{
	int i = 0;
	int array[10] = {0,1,3,2,5,6,9,8,7,4};
	priority_queue<int> v;
	for(i = 0; i < 10; i++)
	{
		v.push(array[i]);
		cout << v.top() << "是目前优先级最高的" << endl;
	}

	cout << "szie is:  " << v.size() << endl;
	//cout << "capacity is:  " << v.capacity() << endl;
	
	for(i = 0; i < 10; i++)
	{
		cout << v.top() << endl;
		v.pop();
	}
	return 0;
}

