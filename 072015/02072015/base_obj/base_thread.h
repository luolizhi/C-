/*************************************************************************
	> File Name: base_thread.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 05:19:45 PM CST
 ************************************************************************/

#ifndef __BASE_THREAD_H__
#define __BASE_THREAD_H__

#include <pthread.h>
#include <functional>

class Thread
{
public:
	typedef std::function<void(void)> ThreadCallback;

public:
	Thread(ThreadCallback callback);
	~Thread();

	void start();
	void join();

	static void * run_in_thread(void*);
	bool is_running() const;

private:
	pthread_t pthread_id_;
	bool is_running_;
	ThreadCallback callback_;
};

#endif
