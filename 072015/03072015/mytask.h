/*************************************************************************
	> File Name: mytask.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 09:18:34 PM CST
 ************************************************************************/

#ifndef __MYTASK_H__
#define __MYTASK_H__

#include "task.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace lukey
{
	class Mytask : public Task
	{
		void process()
		{
			::srand(time(NULL));
			while(1)
			{
				int num = rand() % 100;
				std::cout << "print a num: " << num << std::endl;
				sleep(1);
			}
		}
	};
}//end of namespace lukey

#endif
