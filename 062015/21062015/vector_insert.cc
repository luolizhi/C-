/*************************************************************************
	> File Name: vector_insert.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Mon 22 Jun 2015 09:54:35 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


int main(void)
{
	vector<int> ivec(10,1);
	vector<int>::iterator it;
	for(it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	ivec.insert(ivec.begin(), 3, 4);
	for(it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
