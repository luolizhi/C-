/*************************************************************************
  > File Name: mystring.cc
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Sat 20 Jun 2015 04:10:05 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>



//用来模拟系统的String，练习写时复制，多一个字节保存引用数
class String
{
	friend std::ostream & operator<<(std::ostream &os, String &rhs);
	public:
	String();	//构造函数
	String(const char * str);	//含参数构造函数
	String(const String & rhs);	//复制构造函数，
	String & operator=(const String & rhs);	//赋值运算符函数，这里考虑自复制的情况
	~String();

	const char * c_str()const
	{
		return pstr_;
	}

	int use()
	{
		int len = strlen(pstr_);
		return pstr_[len + 1];	
	}
	private:
	class CharProxy
	{
		public:
			CharProxy(String & str, int idx);	//CharProxy构造函数
			CharProxy & operator=(char c);	//赋值运算符函数，
			operator char() const;

		private:
			String & the_string_;
			int char_index;
	};
	public:
	friend CharProxy;
	CharProxy operator[](int idx);
	const CharProxy operator[](int idx) const;

	private:
	char * pstr_;

}

std::ostream & operator<<(std::ostream & os, String &rhs)
{
	os << rhs.pstr_;
	return os;
}

String::String()
{
	pstr_ = new char[2];	//多申请一个字节，new有初始化哦
	pstr_[1] = 1;	//最后一个字节表示引用个数
}

String::String(const char * str)
{
	int len = strlen(str);
	pstr_ = new char[len + 2];
	strcpy(pstr_, str);
	pstr_[len + 1] = 1;	//带参数构造函数，创建成功把引用计数设为1
}

String::String(const String & rhs)	//复制构造函数
{
	int len = strlen(rhs.pstr_);
	pstr_ = rhs.pstr_;
	++pstr_[len + 1];
}

String String::operator=(const String & rhs)
{
	if(this != &rhs)	//指针指向同一个区域
	{
		int len = strlen(pstr_);
		if(--pstr_[len + 1] == 0)	//原来的引用计数减1为0，只有一个引用，可以删除原来的内存空间
		{
			delete []pstr_;
		}
		//原来的引用计数减1后不为0，表示还有多个引用该空间，也就只用把引用计数减1，不能删除内存空间。

		pstr_ = rhs.pstr_;	//共享内存空间
		len = strlen(pstr_);
		++pstr_[len + 1];	//引用计数加1，之前引用计数已经存在
	}
	return *this;
}

String::~String()
{
	int len = strlen(pstr_);
	if(--pstr_[len + 1] == 0)	//引用减1为0就删除内存空间，否则就只是把引用减1；
	{
		std::cout << "delete []pstr_" << std::endl;
		delete []pstr_;
	}
}

#if 0
//要区分是读操作还是写操作

char & String::operator[](int idx)
{
	static char nullchar = '\0';
	int len = strlen(pstr_);
	if(idx < len && idx >= 0)
	{
		if(--pstr_[len + 1] != 0)//当有两个对象共享同一内存时处理
		{
			char *ptmp = new char[len + 2];
			strcpy(ptmp, pstr_);
			pstr_ = ptmp;
			pstr_[len + 1] = 1;
		}
		else	//引用计数为0
		{
			++pstr_[len + 1];	//只有一个对象指向一段内存
		}

		return pstr_[idx];
	}
	else
	{
		std::cout << "ilegal argument" << std::endl;
		return nullchar;
	}
}


#endif
