/*************************************************************************
  > File Name: threadpool.h
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Fri 03 Jul 2015 10:35:04 AM CST
 ************************************************************************/
#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "noncopyable.h"
//#include "thread.h"
#include "buffer.h"
#include <vector>
//#include "task.h"

namespace lukey
{
	class Task;
	class Thread;
	class Threadpool : public Noncopyable
	{
		public:
			Threadpool(std::size_t numthreads,
					std::size_t bufsize)
				:numthread_(numthreads),
				buf_size_(bufsize),
				buffer_(bufsize),
				is_exit_(false)
		{}

			~Threadpool();

			void add_task(Task *);
			void start();
			void run_in_thread();
		private:
			Task * get_task();
		private:
			std::vector<Thread *> vec_thread_;//这里只是声明，只需要前向声明就行了，不需要引用头文件
			std::size_t numthread_;
			std::size_t buf_size_;
			Buffer buffer_;	//这里要实现，用头文件
			bool is_exit_;
	};

}

#endif
