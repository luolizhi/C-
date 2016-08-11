/*************************************************************************
	> File Name: condition.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 09:42:59 PM CST
 ************************************************************************/

#include "condition.h"
#include "mutexlock.h"
#include<iostream>

namespace lukey
{
	Condition::Condition(MutexLock & mutex)
		:mutex_(mutex)
	{
		std::cout << "Condition()"	<< std::endl;
		pthread_cond_init(&cond_, NULL);
	}

	Condition::~Condition()
	{
		pthread_cond_destroy(&cond_);
	}

	void Condition::wait()
	{
		pthread_cond_wait(&cond_, mutex_.get_mutex_ptr());
	}

	void Condition::signal()
	{
		pthread_cond_signal(&cond_);
	}

	void Condition::broadcast()
	{
		pthread_cond_broadcast(&cond_);
	}


}//end of namespace lukey

