/*************************************************************************
	> File Name: diction.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Mon 27 Jul 2015 10:05:37 AM CST
 ************************************************************************/

#ifndef __DICTION_H__
#define __DICTION_H__

#include <map>
#include <string>
#include <fstream>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "mutexlock.h"
#include "mixsegment.hpp"
#include "encodingconverter.h"

class Diction
{
public:
	static Diction *getInstanc();
	std::map<std::string, int> &getDictMap()
	{
		return dict_map_;
	}
	void buildDictFromRow();

private:
	Diction(const std::string &path,
			const std::string &dict_path,
			const std::string &model_path);
	~Diction();
	void loadDictToMap(const std::string &dictName);
	void readFileToMap(const char *filename);
	void buildExcludeSet();
	void traverseDir(const char *row_path);
	std::ofstream &open_file(std::ofstream &os, const char *filename);//重定义
	std::ifstream &open_file(std::ifstream &is, const char *filename);

	std::map<std::string, int> dict_map_;
	CppJieba::MixSegment segmentor_;
	std::set<std::string> exclude_set_;

	static Diction *instance_;
	static MutexLock lock_;

};

#endif


