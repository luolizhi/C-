/*************************************************************************
	> File Name: mutexlock.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 19 Jul 2015 09:22:26 AM CST
 ************************************************************************/

#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include "noncopyable.h"
#include<pthread.h>

class Mutexlock : public Noncopyable
{
public:
	Mutexlock();
	~Mutexlock();

	void lock();
	void unlock();

	bool isLocked() const;
	pthread_mutex_t * getMutexPtr();	// 得到mutex锁
private:
	pthread_mutex_t mutex_;
	bool isLocking_;
};


#endif


