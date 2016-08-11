/*************************************************************************
	> File Name: configure.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Mon 20 Jul 2015 01:40:06 PM CST
 ************************************************************************/

#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__

#include<map>
#include<string>

#include"mutexlock.h"

//singleton
class Configure
{
public:
	//get configure by name
	std::string getConfigByName(const std::string & name);

	static MutexLock lock_;
	static Configure * getInstance();
private:
	Configure();
	virtual ~Configure();

	void loadConfigureToMap(const std::string & path);
	std::map<std::string, std::string> configure_map_;
	static Configure * config_;
};

#endif
