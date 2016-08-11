/*************************************************************************
	> File Name: mypoolthread.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 10:11:02 PM CST
 ************************************************************************/

#include "mypoolthread.h"
#include "threadpool.h"

namespace  lukey
{
Mypoolthread::Mypoolthread(Threadpool & threadpool)
	:threadpool_(threadpool)
{}

void Mypoolthread::run()
{
	threadpool_.run_in_thread();
}
}

