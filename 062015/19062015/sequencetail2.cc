/*************************************************************************
	> File Name: sequencetail2.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 19 Jun 2015 04:24:19 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<list>
#include<deque>

//using namespace std;
using std::list;
using std::cout;
using std::endl;

int main()
{
	int  arr[5] = {1,2,3,4,5};
	list<int> list_init(arr, arr+5);
	list<int>::iterator iter;
	for(iter = list_init.begin(); iter != list_init.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	list_init.push_front(9);
	//list<int>::iterator iter;
	for(iter = list_init.begin(); iter != list_init.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}
