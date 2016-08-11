/*************************************************************************
	> File Name: test_query.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 21 Jun 2015 09:25:26 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<set>


using std::cin;
using std::cout;
using std::endl;


class QueryResult;

class TestQuery
{
public:
	using line_no = std::vector<std::string>::size_type;

	//构造函数
	TestQuery(std::ifstream &);
	QueryResult query(const std::string &) const;

private:
	std::shared_ptr<std::vector<std::string>> file_;//输入文件
//每个单词到它所在的行号的集合的映射
	std::map<std::string, 
		std::shared_ptr<std::set<line_no>>> wm_;
};

TestQuery::TestQuery(std::ifstream &is):file_(new vector<string>)
{	
	string text;
}

void runQueries(std::ifstream & infile)
{
	//infile是一个ifstream,指向Wimbledon要处理的文件
	TestQuery tq(infile);	//保存文件并建立查询map
	//与用户交互，提示用户输入要查询的单词，完成查询并打印结果
	while(true)
	{
		cout << "enter a word to look for, or q to quit: " ;
		std::string s;
		//如遇到文件结尾或者用户输入了'q'时，循环终止
		if(!(cin >> s) || s == "q")
		{
			break;
		}
		//指向查询并打印结果
		print(cout, tq.query(s)) << endl;
	}
}
