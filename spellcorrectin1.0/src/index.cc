/*************************************************************************
	> File Name: index.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Mon 20 Jul 2015 09:33:20 AM CST
 ************************************************************************/


#include"index.h"
#include"configure.h"
#include"diction.h"
#include"log.h"

#include<fstream>
#include<stdexcept>
#include<cstring>
#include<sstream>

using namespace std;

Index *Index::instance_ = NULL;
MutexLock Index::lock_;

Index *Index::getInstance()
{
	if(instance_ == NULL)
	{
		lock_.lock();
		if(instance_ == NULL)
		{
			instance_ = new Index();
		}
		lock_.unlock();
	}
	return instance_;
}

Index::~Index()
{
	delete instance_;
	instance_ = NULL;
}

void Index::loadIndexMapFromIndexFile()
{
#ifndef NDEBUG
	WRITE_STR(string("start loadIndexMapFromIndexFile---"));
#endif
	Configure *pconf = Configure::getInstanc();
	string home_path = pconf->getConfigByName("home_path");
	string index_path = pconf->getConfigByName("index_path");
	ifstream ifs((home+path + index_path).c_str());//拼接转换
	if(!(ifs.is_open()))//为空时，报错
	{
		throw runtime_error("can not open index file");
	}
	string line;
	//提取关键词
	while(getline(ifs, line))
	{
		istringstream issm(line);//绑定到读取的行
		string keyword;
		issm >> keyword;//读取关键字
		set<IndexVecType::size_type> index_set;
		IndexVecType::size_type index;
		while(issm >> index)
		{
			index_set.insert(index);
		}
		index_map_.insert(make_pair(keyword, index_set));
	}

}


vector<string> Index::splitStringIntoLetters(std::string &keyword)
{
	vector<string> word_letters;
	string::size_type len = keyword.size();
	char *buf = new char[len + 1];
	strcpy(buf, keyword.c_str());
	for(string::size_type i = 0; i < len + 1;)
	{
		if(buf[i] < 0)
		{
			//is gbk
			char *let = new char[3];
			let[0] = buf[i++];
			let[1] = buf[i++];
			let[2] = '\0';
			//insert the letter and it's index in vector into index_map
			string letter(let);
			delete []let;
			//find out wethear the index map contains this keyword or not 
			//if it contains this keyword then add the index-in-vec into set
			word_letters.push_back(letter);
		}
		else if (buf[i] != '\0')
		{
			//is ASCII letter
			char *let = new char[2];
			let[0] = buf[i++];
			let[1] = '\0';
			string letter(let);
			word_letters.push_back(letter);
			delete []let;
		}
		else
		{
			i++;
		}
	}
	return word_letters;
}


void Index::loadIndexVecFromDiction()
{
	if(0 == index_vec_.size())
	{
		//load the diction-data from global dictionary
		Diction *pdict = Diction::getInstance();
		map<string, int> dict_map = pdict->getDictMap();
#ifdef BUILD_INDEX
		cout << "diction.size() is : " << "dict_map.size()" << endl;
#endif
		for(auto &iter : dict_map)
		{
			index_vec_.push_back(iter);
		}
#ifdef BULID_INDEX
		cout << "loadIndexVecFromDiction index_vec_.size() is ***:" << index_vec_.size() << endl;
#endif

	}
}

void Index::buildIndexFromDiction()
{
#ifdef BUILD_INDEX
	WRITE_STR(string("start buildIndexFromDiction--"));
#endif
	loadIndexVecFromDiction();
	cout << "buildIndexFromDiction index vec.size()------------" << index_vec_.size();
	//traverse the index_vec_ and build index;
	for(IndexVecType::size_type ix = 0; ix != index_vec_.size(); ++ix)
	{
		string word = (index_vec_[ix]).first;
		// split it into one letter by one letter
		vector<string> word_letters = splitStringIntoLetters(word);
		for(auto letter : word_letters)
		{
			(index_map_[letter]).insert(ix);
		}
	}
	writeIndexMapToIndexFile();
}

void Index::writeIndexMapToIndexFile()
{
#ifdef BUILD_INDEX
	WRITE_STR(string("start writeIndexMapToIndexFile--"));
#endif
	Configure *pconf = Configure::getInstanc();
	String home_path = pconf->getConfigByName("home_path");
	string index_path = pconf->getConfigByName("index_path");
	ofstream ofs((home_path + index_path).c_str());
	if(!(ofs.is_open()))
	{
		throw runtime_error("can not open index file");
	}
	for(auto iter : index_map_)
	{
		ofs << iter.first << "\t";
		for(auto it_set : iter.second)
		{
			ofs << it_set << " ";
		}
		ofs << "\n";
	}
	ofs.close();
}
