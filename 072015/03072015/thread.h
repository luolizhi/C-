/*************************************************************************
	> File Name: thread.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 04:40:02 PM CST
 ************************************************************************/

#ifndef __THREAD_H__
#define __THREAD_H__

#include "noncopyable.h"
#include <pthread.h>

namespace lukey
{
	class Thread : public Noncopyable 
	{
		public:
			Thread();
			~Thread();
			void start();
			void join();
			virtual void run() = 0;
			static void * run_in_pthread(void *);

		private:
			pthread_t pthread_id_;
			bool is_running_;
	};

}	//end of namespace lukey


#endif
