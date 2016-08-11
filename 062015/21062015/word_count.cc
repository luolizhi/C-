/*************************************************************************
	> File Name: word_count.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 21 Jun 2015 07:02:10 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<map>

using std::cout;
using std::endl;
using std::map;
using std::string;


//using namespace std;

int main(int argc, char* argv[])
{
	map<string,size_t> word_count;
	string word;
	std::ifstream ifs(argv[1]);
	while(ifs >> word)
	{
		++word_count[word];
	}

	//保存在文件中，
	//下一步考虑map中按照单词出现的频率排序
	std::ofstream ofs("dat.txt");
	map<string, size_t>::iterator it;
	for(it = word_count.begin();it != word_count.end();it++)
	{
		ofs << it->first << " " << it->second << endl;
	}


	for(const auto &w : word_count)
		cout << w.first << "  " << w.second << endl;

	ifs.close();
	ofs.close();

	return 0;


}

