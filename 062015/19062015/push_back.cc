/*************************************************************************
	> File Name: push_back.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 19 Jun 2015 09:23:28 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<list>
//using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;



int main(int argc, char * argv[])
{
	vector<string> vec;
	string word;
	while(cin >> word)
	{
		vec.push_back(word);
		cout << "vec.size() = " << vec.size() << endl;
		cout << "vec.capacity() = " << vec.capacity() << endl;
		cout << "vec.max_size() = " << vec.max_size() << endl;
	}
	return 0;
	
}
