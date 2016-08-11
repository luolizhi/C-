#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

struct Record
{
	std::string word;
	int freq;
};




int main()
{
	std::ifstream in("bible.txt");	
	if(!in.good())
	{
		std::cout << "open error" << std::cout;
		return -1;
	}

	std::string line;
	std::vector<std::string> words;
	
	while(getline(in, line))
	{
		std::string word;
		std::stringstream ss(line);
		while(ss >> word)
		{
			words.push_back(word);
		}
	}

	std::cout << "words.size = " << words.size() << std::endl;

	std::vector<Record> word_count;
	std::vector<Record>::iterator it_count;
	
	//std::cout << *it_count << std::endl;

	std::vector<std::string>::iterator it;
	for(it = words.begin(); it != words.end(); it++)
	{
		for(it_count = word_count.begin(); it_count != word_count.end(); it_count++)
		{
			if(*it == it_count->word)
			{
				++(it_count->freq);
				break;
			}
		}
		if(it_count == word_count.end())
		{
			//it_count = new Record[1];
			//it_count->word = *it;
			Record tmp;
			tmp.word = *it;
			tmp.freq = 1;
			word_count.push_back(tmp);
		}
	}
	for(it_count = word_count.begin(); it_count != word_count.end(); it_count++)
	{
		std::cout << it_count->word << " : " << it_count->freq << std::endl;
	}

	in.close();


	return 0;


}

