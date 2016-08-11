/*************************************************************************
	> File Name: noncopyable.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 04:15:38 PM CST
 ************************************************************************/

#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

namespace lukey
{
	class Noncopyable
	{
		protected:
			Noncopyable(){}
			~Noncopyable(){}
		private:
			Noncopyable(const Noncopyable &);//复制构造函数
			Noncopyable & operator=(const Noncopyable &);	//赋值运算符
	};


}	//end of namespace lukey


#endif
