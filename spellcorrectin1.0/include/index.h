/*************************************************************************
	> File Name: index.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 19 Jul 2015 07:21:48 AM CST
 ************************************************************************/

#ifndef __INDEX_H__
#define __INDEX_H__

#include<vector>
#include<map>

#include "mutexlock.h"
//singelton
class Index
{
public:
	static Index * getInstanc();	//获取本类实例

	//vector < word, frequency > 
	typedef std::vector<std::pair<std::string,int> > IndexVecType;

	//hash_map < letter, set< index in the vector > >
	typedef std::unordered_map<std::string, std::set<IndexVexType::size_type> > IndexMapType;

	void buildIndexFromDiction();	//用词典建立下标

	IndexVecType & getIndexVec()	//获取词典数组
	{
		return index_vec_;
	}

	IndexMapType & getIndexMap()	//获取索引map
	{
		return index_map_;
	}

	std::vector<std::string> splitStringIntoLetters(std::string &keyword);	//将关键词分隔成一个一个单词

private:
	Index();
	~Index();

	void loadIndexMapFromIndexFile();	//从索引文件中读取倒排索引
	void loadIndexVecFromDiction();	//从词典中读取词典数据
	void writeIndexMapToIndexFile();	//把倒排索引写入索引文件


	IndexVecType index_vec_;	//vector存储（单词，词频）
	IndexMapType index_map_;	//map存储（字符，set（在vector中出现该单词的下标））

	static MutexLock lock_;	//互斥锁
	static Index *instance_;	//本类实例
};

#endif
