/*************************************************************************
	> File Name: test.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 21 Jun 2015 10:21:22 AM CST
 ************************************************************************/

#include<iostream> 
#include<map>

using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::map;


int main(void )
{
	std::pair<int, std::string> pairs[2] = {
		std::pair<int, std::string>(1,"A"),
		std::pair<int, std::string>(2,"B")
	};

	std::map<int, std::string> map_istr(pairs,pairs + 2);
	std::pair<int, std::string> t(2, "X");
	//std::pair<std::map<std::map<int, std::string>::iterator>, bool> res = map_istr_;

	pair<map<int, string>::iterator, bool>
		res = map_istr.insert(t);

	if(res.second)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "map 已经包含相同关键字的元素"
			<< res.first->first << " "
			<< res.first->second << endl;;
	}
}
