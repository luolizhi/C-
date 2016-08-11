#include<iostream>
#include<string>
#include<sstream>


int main()
{
	std::string line;
	while(getline(std::cin, line))
	{
		std::string word;
		std::stringstream ss(line);	
		while(ss >> word)
		{
			std::cout << word <<std::endl;
		}
	}

	return 0;
}


int test(void)
{
	int ival1 = 512;
	int ival2 = 1024;
	std::stringstream ss;
	ss << "ival1= " << ival1 << " ival2= " << ival2 << std::endl;
	
	std::string str = ss.str();
	std::cout << str;

	while(ss >> str)
	{
		std::cout << str <<std::endl;
	}
	return 0;
}
