/*************************************************************************
	> File Name: auto_ptr.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 25 Jun 2015 04:58:57 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>

//using namespace std;

using std::cout;
using std::endl;

int main(void)
{
	std::auto_ptr<double> apd(new double(7.77));
	std::cout << "*apd = " << *apd << std::endl;
	//std::cout << "*apd = " << apd << std::endl;//Error
	
	double *pd = new double(8.88);
	std::auto_ptr<double> apd2(pd);
	std::cout << "pd   = " << reinterpret_cast<long>(pd) << std::endl;

	cout << endl;

	int *pi = new int(7);
	std::auto_ptr<int> api1(pi);
	std::auto_ptr<int> api2(api1);//复制，发生所有权转移
	std::cout << "*api2 = " << *api2 << std::endl;
	std::cout << "*api1 = " << *api1 << std::endl;

	return 0;
}



