#include<iostream>
#include<string>

void printCin()
{
	std::cout << "bad = " << std::cin.bad() << std::endl;
	std::cout << "fail= " << std::cin.fail() << std::endl;
	std::cout << "eof = " << std::cin.eof() << std::endl;
	std::cout << "good= " << std::cin.good() << std::endl;
}

int main()
{
	printCin();
	int inum;
	while(std::cin >> inum)
	{
		std::cout << "inum = " << inum <<std::endl;
	}
	printCin();

	return 0;
}
