/*************************************************************************
	> File Name: consumerpthread.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 02 Jul 2015 11:03:11 PM CST
 ************************************************************************/

#include "consumerpthread.h"
#include "buffer.h"
#include <unistd.h>
#include <iostream>

namespace lukey
{
	Consumerpthread::Consumerpthread(Buffer & buffer)
		:buffer_(buffer)
	{}

	Consumerpthread::~Consumerpthread()
	{}


	void Consumerpthread::run()
	{
		process_task();
	}

	void Consumerpthread::process_task()
	{
		while(1)
		{
			int num = buffer_.pop();
			std::cout << "consumer a num: " << num << std::endl;
			sleep(5);
		}
	}
	
}//end of namespace lukey


