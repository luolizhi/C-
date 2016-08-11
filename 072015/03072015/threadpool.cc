/*************************************************************************
	> File Name: threadpool.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 10:02:18 PM CST
 ************************************************************************/


#include "threadpool.h"
#include "mypoolthread.h"
#include "task.h"

namespace lukey
{
Threadpool::~Threadpool()
{
	if(is_exit_ == false)
	{
		is_exit_ = true;
		std::vector<Thread *>::iterator it;
		for(it = vec_thread_.begin(); it != vec_thread_.end(); it++)
		{
			(*it)->join();
			delete *it;
		}
	}
	vec_thread_.clear();	//vector自带功能
}
void Threadpool::start()
{
	for(std::size_t idx = 0; idx != numthread_; idx++)
	{
		Thread * pthread = new Mypoolthread(*this);//基类指针指向派生类
		vec_thread_.push_back(pthread);
		pthread->start();
	}
}

void Threadpool::add_task(Task * ptask)
{
	buffer_.push(ptask);
}

Task * Threadpool::get_task()
{
	return buffer_.pop();
}

void Threadpool::run_in_thread()
{
	while(!is_exit_)
	{
		Task *ptask = get_task();
		if(ptask != NULL)
			ptask -> process();
	}
}

}//end of namespace lukey
