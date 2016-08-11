/*************************************************************************
	> File Name: test_main.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 09:31:43 AM CST
 ************************************************************************/


#include "mytask.h"
#include "threadpool.h"
#include <unistd.h>
#include <iostream>


int main(void)
{
	lukey::Task * ptask = new lukey::Mytask;
	lukey::Threadpool threadpool(4, 10);
	threadpool.start();

	while(1)
	{
		threadpool.add_task(ptask);
		sleep(1);
	}

	delete ptask;
	return 0;
}
