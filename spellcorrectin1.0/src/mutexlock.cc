/*************************************************************************
	> File Name: mutexlock.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 19 Jul 2015 09:46:22 AM CST
 ************************************************************************/


#include "mutexlock.h"
#include<iostream>


Mutexlock::Mutexlock()
{
	std::cout << "Mutexlock()" << std::endl;
	pthread_mutex_init(&mutex_, NULL);
	isLocking_ = false;
}

Mutexlock:~Mutexlock()
{
	pthread_mutex_destroy(&mutex_);
}

void Mutexlock::lock()
{
	pthread_mutex_lock(&mutex_);
	isLocking_ = true;
}

void Mutexlock::unlock()
{
	pthread_mutex_unlock(&mutex_);
	isLocking_ = false;
}

bool isLocked() const
{
	return isLocking_;
}

pthread_mutex_t * Mutexlock::getMutexPtr()
{
	return & mutex_;	//返回引用
}
