/*************************************************************************
	> File Name: mutexlock.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 08:51:36 PM CST
 ************************************************************************/

#include "mutexlock.h"
#include <iostream>

namespace lukey
{
	MutexLock::MutexLock()
		:is_locking_(false)
	{
		std::cout << "MutexLock::MutexLock()" << std::endl;
		pthread_mutex_init(&mutex_, NULL);
	}


	MutexLock::~MutexLock()
	{
		pthread_mutex_destroy(&mutex_);
	}

	void MutexLock::lock()
	{
		pthread_mutex_lock(&mutex_);
		is_locking_ = true;
	}

	void MutexLock::unlock()
	{
		pthread_mutex_unlock(&mutex_);
		is_locking_ = false;
	}
	

	bool MutexLock::is_locked() const
	{
		return is_locking_;
	}

	pthread_mutex_t * MutexLock::get_mutex_ptr()
	{
		return & mutex_;
	}

	MutexLockGuard::MutexLockGuard(MutexLock & mutex)
		:mutex_(mutex)
	{
		mutex_.lock();
	}

	MutexLockGuard::~MutexLockGuard()
	{
		mutex_.unlock();
	}


}//end of namespace lukey
