/*************************************************************************
	> File Name: stack.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 23 Jun 2015 09:41:22 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
#include<string>

//using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::stack;
using std::string;


int main(void)
{
	stack<int, vector<int> > object_int;	
	for(int i = 1; i <= 20; i++)
		object_int.push(i);

	while(object_int.size() > 0)
	{
		int x = object_int.top();
		cout << x << " ";
		object_int.pop();
	}
	cout << endl;

	stack<string, vector<string> > object_string;
	for(char c = 'A'; c <= 'Z'; c++)
	{
		string s(2, c);	//创建一个string，由两个c组成
		object_string.push(s);
	}

	while(object_string.size() > 0)
	{
		string s = object_string.top();
		cout << s << endl;;
		object_string.pop();
	}

	cout << endl;
	return 0;
}

