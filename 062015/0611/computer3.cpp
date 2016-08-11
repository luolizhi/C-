/*************************************************************************
	> File Name: computer3.cpp
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 11 Jun 2015 08:21:15 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>

using namespace std;

class computer
{
	private:
		char* brand_;
		float price_;
	public:
		computer(const char *pbrand, float price)
		{
			brand_ = new char[strlen(pbrand) + 1];
			strcpy(brand_, pbrand);
			price_ = price;
		}
		~computer()
		{
			delete []brand_;
			brand_ = NULL;
			std::cout << "清理现场" << std::endl;
		}
		void print()
		{
			std::cout << "品牌 " << brand_ << std::endl;
			std::cout << "价格 " << price_ << std::endl;
		}
};


int main()
{
	computer pc1("lenovo", 4999);
	pc1.print();

	{
	static computer pc4("mac",10000);
	pc4.print();
	}
	std::cout << "pc2" << std::endl;
	{
	computer pc2("Dell",6999);
	pc2.print();
	}
	std::cout << "pc2" << std::endl;

#if 0
	computer *pc3;
	pc3 = new computer("acer",3999);
	pc3->print();
	delete pc3;
	pc3 = NULL;
#endif
	return 0;
}

