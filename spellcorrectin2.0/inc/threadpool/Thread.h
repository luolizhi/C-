/*************************************************************************
	> File Name: Thread.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Wed 07 Oct 2015 04:13:03 PM CST
 ************************************************************************/

#ifndef __THREAD_H__
#define __THREAD_H__

#include <functional>
#include <pthread.h>
#include "NonCopyable.h"

class Thread : private NonCopyable
{
public:
	typedef std::function<void ()> ThreadCallback;
	explicit Thread(ThreadCallback callback);
	~Thread();

	void start();
	void join();

private:
	static void *runInThread(void *);

	pthread_t threadId_;
	bool isRunning_;
	ThreadCallback callback_;
};

#endif




