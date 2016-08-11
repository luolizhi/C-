#include<iostream>
#include<stdio.h>
class Point
{
	private:
		int ix_;
		int iy_;
	public:
		static int icount_;
#if 1
		Point()	//带缺省参数值的构造函数
			:ix_(0),iy_(0)
		{
			std::cout << "调用默认构造函数" << std::endl;
			icount_++;
			std::cout << "icount_ = " << icount_ << std::endl;
		}
#endif 
		void print()
		{
			std::cout << "(" << ix_ << "," << iy_ << ")" << std::endl;
		}
};

int Point::icount_ = 0;

int main()
{
	Point pt[2];
	pt[0].print();
	pt[1].print();
	printf("icount_ = %d\n", Point::icount_);
	return 0;
}
