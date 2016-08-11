/*************************************************************************
  > File Name: thread.cc
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Thu 02 Jul 2015 04:53:58 PM CST
 ************************************************************************/

#include "thread.h"
#include<iostream>

namespace lukey
{
	Thread::Thread()
		:pthread_id_(0),
		is_running_(false)
	{
		std::cout << "Thread::Thread()" << std::endl;
	}

	Thread::~Thread()
	{
		std::cout << "Thread::Thread()" << std::endl;
		pthread_detach(pthread_id_);
	}
	void Thread::start()
	{
		pthread_create(&pthread_id_, NULL, run_in_pthread , this);
		is_running_ = true;
	}


	void Thread::join()
	{
		pthread_join(pthread_id_, NULL);
		is_running_ = false;
	}

	void * Thread::run_in_pthread(void * arg)	//static,不带this指针
	{
		Thread * pthread = static_cast<Thread *>(arg);
		pthread->run();
		return NULL;
	}



}	// end of namespace lukey
