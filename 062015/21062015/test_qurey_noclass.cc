/*************************************************************************
	> File Name: test_qurey_noclass.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 21 Jun 2015 10:04:11 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<set>

#include<cstdlib>
//#include"make_plural.h"
using namespace std;
using line_no  vector<string>::size_type;

vector<string> file;	//文件每行内容
map<string,string<line_no>> wm;	//word_map

string cleanup_str(const string & word)
{
	string ret;
	for(auto it = word.begin();it != word.end(); it++)
	{
		if(!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

void input_text(ifstream &is)
{
	string text;
	while(getline(is, text))
	{
		file.push_back(text);	//保存此行文本
		int n = file.size() - 1;	//当前行号
		istreamstring line(text);	//将文本分解为单词
		string word;
		while(line >> word)
		{
			//讲当前行号插入到某行号set中
			//如果单词不在wm中，以之为下标在wm中添加一项
			wm[cleanup_str(word)].insert(n);
		}
	}
}

ostream &query_and_print(const string &sought, ostream & os)
{
//使用find而不是下标运算符来查找单词，避免将单词添加到wm中
	auto loc = wm.find(sought);
	if(loc == wm.end())	//未找到
	{
		os << sought << "出现了0次" << endl;
	}
	else
	{
		auto lines = loc->second;
		os << sought << "出现了" << lines.size() << "次" << endl;
		for(auto num : lines)
		{
			os << "\t(第" << num + 1 << "行) "
				<< *(file.begin() + num) << endl;
		}
	}
	return os;
}

void runQueries(ifstream & infile)
{
	//infile 是一个ifstream，指向我们要查询的文件
	input_text(infile);
	//与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while(true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q") break;

		query_and_print(s, cout) << endl;
	}
}

int main(int argc, char * argv[])
{
	//打开要查询的文件
	ifstream infile;
	//打开文件失败，程序异常退出
	if(argc < 2 || !(infile.open(argv[1]), infile))
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	} 
	runQueries(infile);

	return 0;
}
