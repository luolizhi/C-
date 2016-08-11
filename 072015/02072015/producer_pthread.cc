/*************************************************************************
	> File Name: producer_pthread.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 10:49:49 PM CST
 ************************************************************************/

#include "producer_pthread.h"
#include "buffer.h"
#include <iostream>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


namespace lukey
{
	Producerpthread::Producerpthread(Buffer & buffer)
		:buffer_(buffer)
	{
		std::cout << "Producerpthread()" << std::endl;
	}

	Producerpthread::~Producerpthread()
	{}

	void Producerpthread::run()
	{
		process_task();
	}

	void Producerpthread::process_task()
	{
		::srand(time(NULL));
		while(1)
		{
			int num = rand() % 100;
			buffer_.push(num);
			std::cout << "produce a num: " << num << std::endl;
			sleep(1);
		}
	}

}

