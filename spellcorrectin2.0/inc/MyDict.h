/*************************************************************************
	> File Name: MyDict.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sat 05 Sep 2015 07:41:00 PM CST
 ************************************************************************/

#ifndef __MYDICT_H__
#define __MYDICT_H__

//singleton

#include <string>
#include <vector>
#include <set>
#include <utility>
#include <map>

class MyDict
{
public:
	static MyDict *creatInstance(const char *dictpath);

	std::vector<std::pair<std::string, int> > &get_dict();
	std::map<std::string, std::set<int> > &get_index_table();

	void show_dict();
	void show_index_table();


private:
	MyDict(const char *dictpath);
	void record_to_index(int idx);
private:
	static MyDict *pInstance;
	std::vector<std::pair<std::string, int> > dict_;
	std::map<std::string, std::set<int> > index_table_;
};

#endif //end __MYDICT_H__


