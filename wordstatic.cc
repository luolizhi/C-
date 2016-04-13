#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>


struct Record
{
	std::string word;
	int freq;
};

class WordStatics
{
	public:
		void readfile(const std::string &filename);

		void writefile(const std::string &filename);
		
		void quicksort(std::vector<Record> &vec,int low, int high);

		void sort(const std::string &filename);

	private:
		std::vector<Record> dict_;

};

void WordStatics::readfile(const std::string & filename)	//传入要读取文件的地址
{
	std::ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		std::cout << "ifs error" << std::endl;
		return;
	}
	
	std::string line;
	while(getline(ifs, line))
	{
	//	std::cout << "line: " << line << std::endl;
		std::stringstream ss(line);	//用字符创流关联
		std::string word;
		while(ss >> word)	//按照空格读取单词
		{
	//		std::cout << "word:" << word << std::endl;
			std::vector<Record>::iterator it;
			for(it = dict_.begin(); it != dict_.end(); it++)
			{
				if(it->word == word)
				{
					 (it->freq)++;
					 break;
				}
			}

			if(it == dict_.end())
			{
				Record temp;
				temp.word = word;
				temp.freq = 1;
				dict_.push_back(temp);	
			}
		}
	}
	ifs.close();
}

void WordStatics::writefile(const std::string &filename)
{
	std::ofstream out(filename.c_str());
	if(!out.good())
	{
		std::cout << "outfile error" << std::endl;
		return ;
	}
	
	std::vector<Record>::iterator it;
	for(it = dict_.begin(); it != dict_.end(); it++)
	{
		out << it->word << " " << it->freq <<std::endl;
	}
	
	out.close();
}


void WordStatics::sort(const std::string & filename)
{
#if 0
	std::ofstream out_sort(filename.c_str());
	if(!out_sort.good())
	{
		std::cout << "out_sort error" << std::endl;
		return;
	}
#endif
	std::vector<Record>::iterator it, it2,it_begin, it_end;

	//冒泡排序
	for(it = dict_.begin(); it != dict_.end(); it++)
	{
		for(it2 = it; it2 != dict_.end(); it2++)
		{
			if(it->freq < it2->freq)	//如果前面的词频小于后面的，就交换
			{
				Record temp;
				temp = *it;
				*it = *it2;
				*it2 = temp;
			}
		}
	}

	WordStatics::writefile(filename);
#if 0
	//计划写快速排序，没写出来
	for(it_begin = dict_.begin(), it_end = dict_.end();it_begin <= it_end; it_begin++, it_end--)
	{
		
	}
#endif
}

int main()
{
	std::string rdfilename = "bible.txt";
	std::string outfilename = "dat3.txt";
	WordStatics ws;
	ws.readfile(rdfilename);
	ws.sort(outfilename);
	
	return 0;
}
