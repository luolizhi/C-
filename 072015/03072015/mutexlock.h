/*************************************************************************
  > File Name: mutexlock.h
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Thu 02 Jul 2015 08:30:15 PM CST
 ************************************************************************/

#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include "noncopyable.h"
#include<pthread.h>

namespace lukey
{
	class MutexLock : public Noncopyable
	{
		public:
			MutexLock();
			~MutexLock();

			void lock();
			void unlock();

			bool is_locked() const;
			pthread_mutex_t * get_mutex_ptr();

		private:
			pthread_mutex_t mutex_;
			bool is_locking_;
	};	//end of class MutexLock

	class MutexLockGuard
	{
		public:
			MutexLockGuard(MutexLock & mutex);	//要传参
			~MutexLockGuard();

		private:
			MutexLock & mutex_; //引用
	};



}//end of namespace lukey

#endif
