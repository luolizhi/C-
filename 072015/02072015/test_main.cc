/*************************************************************************
	> File Name: test_main.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Fri 03 Jul 2015 09:31:43 AM CST
 ************************************************************************/

#include "producer_pthread.h"
#include "consumerpthread.h"
#include "buffer.h"

int main(void)
{
	lukey::Buffer buffer(10);
	lukey::Producerpthread *p_producer = new lukey::Producerpthread(buffer);
	lukey::Consumerpthread *p_consumer = new lukey::Consumerpthread(buffer);

	p_producer->start();
	p_consumer->start();

	p_producer->join();
	p_consumer->join();

	delete p_producer;
	delete p_consumer;

	return 0;
}
