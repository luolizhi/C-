/*************************************************************************
	> File Name: conf.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sat 05 Sep 2015 07:19:18 PM CST
 ************************************************************************/

#ifndef __CONF_H__
#define __CONF_H__

#include <string>
#include <fstream>
#include <sstream>
#include <map>

class MyConf
{
public:
	MyConf(std::string &);

	bool init();
	
	std::map<std::string, std::string> &get_map()
	{
		return map_;
	}

	void show();

private:
	std::ifstream in_;
	std::map<std::string, std::string> map_;

};

#endif

