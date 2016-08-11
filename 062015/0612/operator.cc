#include<iostream>

class Mycomplex
{
	private:
		double real;
		double imag;	//复数的虚部
	public:
		//构造函数，带缺省参数值
		Mycomplex(double r = 0.0, double i = 0.0)
			:real(r),imag(i)
		{}
		
		Mycomplex operator+= (const Mycomplex &);	//成员函数形式重载+=
		Mycomplex operator+ (const Mycomplex &);
		Mycomplex operator- (const Mycomplex &);
		Mycomplex operator* (const Mycomplex &);
		Mycomplex operator/ (const Mycomplex &);
		Mycomplex & operator++ ();	//前置++
		Mycomplex operator++ ();	//后置++
		void display();
};

Mycomplex Mycomplex::operator+= (const Mycomplex & cc)
{
	real += cc.real;
	imag += cc.imag;
	return (*this);
}
Mycomplex Mycomplex::operator+ (const Mycomplex & cc)
{
	return Mycomplex(real+cc.real, imag+cc.imag);
}

Mycomplex Mycomplex::operator* (const Mycomplex & cc)
{
	return Mycomplex(real * cc.real - imag * cc.imag, real * cc.imag + imag * cc.real);
}

Mycomplex Mycomplex::operator/ (const Mycomplex & cc)
{
	return Mycomplex((real * cc.real + imag + cc.imag)/(cc.real * cc.real + cc.imag * cc.imag),
			(imag * cc.real - real * cc.imag)/(cc.real * cc.real + cc.imag * cc.imag));
}

Mycomplex & Mycomplex::operator++ ()
{
	std:: << "前置++" << std::endl;
	++real;
	++imag;
	return (*this);
}

Mycomplex Mycomplex::operator++ ()
{
	std:: << "后置++" << std::endl;
	Mycomplex ctemp = (*this);
	++(*this);
	return ctemp;

}

void Mycomplex::display()
{
	std::cout << real << "+" << imag << "*i" << std::endl;
}

int main(void)
{
	Mycomplex com1(2,1),com2(3,3.0), com_ret;
	com1.display();
	com2.display();

	com_ret = com1 + com2;
	com_ret.display();
	
	com_ret += com1;
	com_ret.display();
	return 0;
}
