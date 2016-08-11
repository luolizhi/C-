/*************************************************************************
	> File Name: noncopyable.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 19 Jul 2015 10:05:25 AM CST
 ************************************************************************/

#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__
class Noncopyable
{
protected:
	Noncopyable(){}
	virtual ~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &){}
	Noncopyable & operator=(const Noncopyable &)
	{
		return *this;
	}
};
#endif
