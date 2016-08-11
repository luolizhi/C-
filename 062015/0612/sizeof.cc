#include <iostream>

class size
{
private:
	int a;			//4
	char b;			//1
	float c;		//4
	double d;		//8
	short e[5];		//10
	char & f;		//4
	double & g;
	static int h;

};

int main(void)
{
	std::cout << "sizeof(size)" << sizeof(size) << std::endl;
	return 0;
	
}
