#include<iostream>

class CNullPointCall
{
	public:
		static void Test1();
		void Test2();
		void Test3(int itest);
		void Test4();
	private:
		static int m_istatic;
		int m_itest;
};

int CNullPointCall::m_istatic = 0;

void CNullPointCall::Test1()
{
	std::cout << m_istatic << std::endl;
	//std::cout << m_itest << std::endl;
}

void CNullPointCall::Test2()
{
	std::cout << "Very Cool!" << std::endl;
}

void CNullPointCall::Test3(int itest)
{
	std::cout << itest << std::endl;
}

void CNullPointCall::Test4()
{
	std::cout << m_itest << std::endl;
}
int main()
{
	CNullPointCall c1;
	c1.Test1();
	c1.Test2();
	c1.Test3(5);
	c1.Test4();

	return 0;
}
