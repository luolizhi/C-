/*************************************************************************
	> File Name: mypoolthread.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 10:04:25 PM CST
 ************************************************************************/

#ifndef __MYPOOLTHREAD_H__
#define __MYPOOLTHREAD_H__

#include "thread.h"

namespace lukey
{
class Threadpool;
class Mypoolthread : public Thread
	{
		public:
			Mypoolthread(Threadpool & threadpool);

			void run();

		private:
			Threadpool & threadpool_;
	};
}

#endif
