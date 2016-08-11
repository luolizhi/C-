/*************************************************************************
	> File Name: rvo.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 25 Jun 2015 09:43:18 AM CST
 ************************************************************************/

#include<iostream>
#include<iomanip>

using namespace std;

int num = 1;
class A
{
public:
	//构造函数
	A()
	{
		id = count++;
		pre_id = -1;
		cout << setw(2) << num++ << " :A():id=" << id
			<< " pre_id=" << pre_id << endl;
	}
//复制构造函数
	A(const A &a)
	{
		id = count++;
		pre_id = a.id;
		cout << setw(2) << num++ << " :A(const A &a):id=" << id
			<< " pre_id=" << pre_id << endl;
	}
//析构函数
	~A()
	{
		cout << setw(2) << num++ << " :~A():id=" << id
			<< " pre_id=" << pre_id << endl;

	}
	//赋值运算符
	A &operator=(const A &a)
	{
		pre_id = a.id;
		
		cout << setw(2) << num++ << " : =(const A&):id=" << id
			<< " pre_id=" << pre_id << endl;
	}
private:
	static int count;
	int id;
	int pre_id;
};

int A::count = 0;

A f()
{
	A a;
	return a;	//临时对象，是右值，不优化会调用复试构造函数
}

A g1(A b)
{
	A a = b;
	return a;
}

A g2(A b)
{
	A a;
	a = b;
	return a;
}

int main(void)
{
	A b1 = f();
	cout << "======" << endl;
	A b2 = g1(b1);
	cout << "======" << endl;
	A b3 = g2(b1);
	A c1, c2, c3;
	cout << "======" << endl;
	c1 = f();
	cout << "======" << endl;
	c2 = g1(c1);
	cout << "======" << endl;
	c3 = g2(c1);
	cout << "======" << endl;

	return 0;
}

