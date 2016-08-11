/*************************************************************************
	> File Name: buffer.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 09:51:53 PM CST
 ************************************************************************/

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "noncopyable.h"
#include "mutexlock.h"
#include "condition.h"
#include <queue>

namespace lukey
{
	class Buffer : public Noncopyable
	{
		public:
			Buffer(std::size_t num);
			~Buffer();

			void push(int no);

			int pop();

			bool empty();
			bool full();

		private:
			MutexLock mutex_;
			Condition not_full_;
			Condition not_empty_;
			
			std::size_t max_size_;
			std::queue<int> que_;
	};

}//end of namespace lukey


#endif



