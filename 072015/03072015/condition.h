/*************************************************************************
	> File Name: condition.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 09:34:12 PM CST
 ************************************************************************/

#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "noncopyable.h"
#include <pthread.h>
//#include "mutexlock.h"

namespace lukey
{
	class MutexLock;
	class Condition : public Noncopyable	//继承，都不能复制和赋值
	{
		public:
			Condition(MutexLock & mutex);
			~Condition();

			void wait();	//需要mutex
			void signal();
			void broadcast();
	
		private:
			pthread_cond_t cond_;
			MutexLock & mutex_;
	};





}//end of namespace lukey


#endif
