/*************************************************************************
	> File Name: producer_pthread.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 10:38:34 PM CST
 ************************************************************************/

#ifndef __PRODUCER_PTHREAD_H__
#define __PRODUCER_PTHREAD_H__

#include "thread.h"
#include "buffer.h"


namespace lukey
{
	class buffer;//声明
	class Producerpthread : public Thread
	{
		public:
			Producerpthread(Buffer & buffer);
			virtual ~Producerpthread();
	
			void run();

		private:
			void process_task();
		private:
			Buffer & buffer_;
	
	};

}//end of namespace lukey


#endif
