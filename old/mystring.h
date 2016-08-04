/*************************************************************************
  > File Name: mystring.h
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Wed 17 Jun 2015 08:50:49 PM CST
 ************************************************************************/

#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
	public:
		String();
		String(const char *);//有参构造函数
		String(const String & rhs);	//复制构造
		~String();

		String & operator=(const String & rhs);//赋值运算符的两种情况
		String & operator=(const char *str);

		String & operator+=(const String & rhs);
		String & operator+=(const char * str);

		char & operator[](std::size_t index);
		const char & operator[](std::size_t index) const;

		std::size_t size() const;
		const char* c_str() const;
		void debug();

		//String 类和char相加的几个情况
		friend String operator+(const String & s1, const String & s2);
		friend String operator+(const String &, const char *);
		friend String operator+(const char *, const String &);

		friend bool operator==(const String &, const String &);
		friend bool operator!=(const String &, const String &);

		friend bool operator<(const String &, const String &);
		friend bool operator>(const String &, const String &);
		friend bool operator<=(const String &, const String &);
		friend bool operator>=(const String &, const String &);

		friend std::ostream & operator<<(std::ostream & os, const String &s);
		friend std::istream & operator>>(std::istream & is, String & s);

	private:
		char *pstr_;
};

#endif
