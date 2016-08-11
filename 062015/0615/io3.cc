#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main(void)
{
	std::ifstream ifs("io.cc");
	if(!ifs.good())
	{
		std::cout << "ifstream error" << std::endl;
		return -1;
	}

	std::ofstream ofs("test.txt");	//默认情况下就是以out的方式打开
	std::string line;
	while(getline(ifs, line))
	{
		ofs << line << std::endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}






int test(void)
{
	std::ifstream ifs("io.cc");
	if(!ifs.good())
	{
		std::cout << "ifstream error" << std::endl;
		return -1;
	}

	std::string s;
#if 0
	while(ifs >> s)	//对于字符串，空格作为默认的分隔符
	{
		std::cout << s << std::endl;
	}
	while(getline(ifs, s))	//获取一行字符串
	{
		std::cout << s << std::endl;
	}
#endif
	std::vector<std::string> vec_str;
	while(getline(ifs, s))
	{
		vec_str.push_back(s);
	}
	
	std::vector<std::string>::iterator it;	//迭代器
	for(it = vec_str.begin(); it != vec_str.end(); it++)
	{
		std::cout << *it << std::endl;
	}
		std::cout << "vec_str's size = " << vec_str.size() << std::endl;

		ifs.close();
	

	return 0;
}

