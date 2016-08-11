#include<iostream>
#include<stdio.h>

class Singleton
{
	private:
		//构造函数带花括号，或者是类内声明，类外定义
		Singleton(){}

	public:
		static Singleton *psingleton;
		static Singleton * createInstance()
		{
			if(psingleton == NULL)
			{
				psingleton = new Singleton();
			}

			return psingleton;
		}
};

Singleton* Singleton::psingleton = NULL;

int main(void)
{
	Singleton *p1 = Singleton::createInstance();
	Singleton *p2 = Singleton::createInstance();
	
	printf("p1 = %x\n", (unsigned int)p1);
	printf("p2 = %x\n", (unsigned int)p2);

}
