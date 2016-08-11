/*************************************************************************
	> File Name: MutexLock.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 07 Oct 2015 03:37:46 PM CST
 ************************************************************************/

#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include "NonCopyale.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// 用于pthread系列函数的返回值检查
#define TINY_CHEK(exp) \
	if(!(exp))\
{\
	fprintf(stderr, "File:%s, Line:%d Exp:[" #exp "] is true, abort.\n", __FILE__, __LINE__,);abort();\
}

class MutexLock : NonCopyable
{
	friend class Condition;
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();

	bool isLocking() const {return isLocking_;}
	pthread_mutex_t *getMutexPtr()	//why not const
	{return &mutex_;}

private:
	void restoreMutexStatus()	//提供给Condition的wait使用
	{isLocking_ = true;}

	pthread_mutex_t mutex_;
	bool isLocking_;
};

class MutexLockGuard : NonCopyable
{
public:
	MutexLockGuard(MutexLock &mutex) : mutex_(mutex)
	{mutex_.lock(); }
	~MutexLockGuard()
	{mutex_.unlock(); }

private:
	MutexLock &mutex_;
};

#define MutexLockGuard(m) "Error MutexLockGuard"

#endif //
