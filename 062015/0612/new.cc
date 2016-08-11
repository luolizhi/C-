#include<iostream>

class Point
{
	private:
		int x_;
		int y_;
	public:
		//构造函数，带缺省参数值
		Point(int xp = 0, int yp = 0)
			:x_(xp), y_(yp)
		{
			std::cout << "调用构造函数" << std::endl;	
		}
		~Point()
		{
			std::cout << "析构函数" << std::endl;
		}

		void print()	//成员函数，类内部实现
		{
			std::cout << "x: " << x_ << ", y: " << y_ << std::endl;
		}
		
		void Set(int xp, int yp);//成员函数，类外部实现
};

void Point::Set(int xp, int yp)
{
	x_ = xp;
	y_ = yp;
}

int main (void)
{
	Point * p = new Point[2];
	p[0].print();
	p[1].print();

	p[1].Set(4,5);
	p[1].print();

	delete []p;
	p = NULL;

	return 0;
}
