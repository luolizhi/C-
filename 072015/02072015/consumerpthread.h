/*************************************************************************
	> File Name: consumerpthread.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 10:57:25 PM CST
 ************************************************************************/

#ifndef __CONSUMERPTHREAD_H__
#define __CONSUMERPTHREAD_H__

#include "thread.h"
//#include "buffer.h"

namespace lukey
{
	class Buffer;
	class Consumerpthread : public Thread
	{
		public:
			Consumerpthread(Buffer &);
			virtual ~Consumerpthread();

			void run();
		private:
			void process_task();
		private:
			Buffer & buffer_;
	};

}//end of namespace lukey


#endif
