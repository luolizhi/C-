#include<iostream>
#include<stdio.h>
#include<string.h>

class String
{
	public:
		String()
		{
			std::cout << "String()" << std::endl;
			//pstr_ = NULL;//Error
			pstr_ = new char[1];
		}

		String(const char *pstr)
		{
			pstr_ = new char[strlen(pstr) + 1];
			strcpy(pstr_, pstr);
		}

		String(String const & rhs)
		{
			std::cout << "String(const String &)" << std::endl;
			pstr_ = 
			
		}
		~String()
		{
			delete pstr_;
		}

		void print()
		{
			//std::cout << pstr_ << std::endl;
			printf("%s\n", pstr_);
		}
	private:
		char * pstr_;
};

int main()
{
	String s1;
	s1.print();

	std::cout << "hello world" << std::endl;
	return 0;
}
