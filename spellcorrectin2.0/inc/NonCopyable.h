/*************************************************************************
	> File Name: NonCopyable.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sat 05 Sep 2015 07:14:10 PM CST
 ************************************************************************/

#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

class NonCopyable
{
protected:
	NonCopyable(){}
	~NonCopyable(){}

private:
	NonCopyable(const NonCopyable &);	//复制构造函数
	NonCopyable &operator=(const NonCopyable &);//赋值函数
};

#endif	//end of NONCOPYABLE
