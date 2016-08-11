/*************************************************************************
	> File Name: thread.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 05:25:36 PM CST
 ************************************************************************/

#include "base_thread.h"
#include <iostream>

Thread::Thread(ThreadCallback callback)
	:pthread_id_(0),
	is_running_(false),
	callback_(callback)
{
	std::cout << "Thread::Thread()" << std::endl;
}

Thread::~Thread()
{
	pthread_detach(pthread_id_);
	is_running_ = false;
}

void Thread::start()
{
	pthread_create(&pthread_id_, NULL, run_in_thread, this);
	is_running_ = true;
}

void Thread::join()
{
	pthread_join(pthread_id_, NULL);
	is_running_ = false;
}

void *Thread::run_in_thread(void *arg)
{
	Thread * pThread = static_cast<Thread *>(arg);
	pThread->callback_();
}

bool Thread::is_running() const
{
	return is_running_;
	}
