/*************************************************************************
	> File Name: Condition.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 07 Oct 2015 03:32:51 PM CST
 ************************************************************************/

#ifndef __CONDITIN_H__
#define __CONDITIN_H__

#include "NonCopyable.h"
#include <pthread.h>

class MutexLock;

class Conditin : NonCopyable
{
public:
	Condition(MutexLock &mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

private:
	pthread_cond_t cond_;
	MutexLock &mutex_;
};


#endif //CONDITION_H_
