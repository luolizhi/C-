/*************************************************************************
	> File Name: task.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 10:19:49 AM CST
 ************************************************************************/

#ifndef __TASK_H__
#define __TASK_H__
//#include "noncopyable.h"

namespace lukey
{
	class Task //: public Noncopyable
	{
		public:
			//Task(){}
			virtual ~Task(){}

			virtual void process()=0;
	};


}//end of namespace lukey

#endif
