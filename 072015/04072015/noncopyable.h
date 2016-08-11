/*************************************************************************
	> File Name: noncopyable.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 07 Jul 2015 03:02:48 PM CST
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
		Noncopyable(const Noncopyable &);
		Noncopyable & operator=(const Noncopyable &);
};

}//end of namespace lukey


#endif


