/*************************************************************************
	> File Name: buffer.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 10:10:11 PM CST
 ************************************************************************/

#include "buffer.h"
#include<iostream>


namespace lukey
{
	Buffer::Buffer(std::size_t num)
		:not_full_(mutex_),
		not_empty_(mutex_),
		max_size_(num)
	{
		std::cout << "Buffer(size_t num)" << std::endl;
	}

	Buffer::~Buffer()
	{
		std::cout << "~Buffer()" << std::endl;
	}

	void Buffer::push(int no)
	{
		MutexLockGuard mtg(mutex_);//执行加锁操作，会自动解锁，解锁在析构函数中
		while(full())	//full是哪里的函数？
		{
			not_full_.wait();
		}

		que_.push(no);
		not_empty_.signal();//发一个通知
	}

	 int Buffer::pop()
	 {
		MutexLockGuard mtg(mutex_);
		while(empty())
		{
			not_empty_.wait();
		}

		int num = que_.front();
		que_.pop();
		not_full_.signal();
		return num;
	 }

	 bool Buffer::empty()
	 {
		return que_.empty();
	 }

	 bool Buffer::full()
	 {
		return max_size_ == que_.size();
	 }


}//end of namespace lukey


