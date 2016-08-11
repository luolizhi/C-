/*************************************************************************
	> File Name: SocketIO.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 06 Sep 2015 05:18:34 PM CST
 ************************************************************************/

#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

#include "NonCopyable.h"
#include <sys/types.h>

//ssize_t  long int /int(32)
//size_t  unsinged long / unsinged int(32)

class SocketIO : private NonCopyable
{
public:
	explicit SocketIO(int sockfd);
	: sockfd_(sockfd)
	{
	}

	ssize_t readn(char *buf, size_t count);
	ssize_t writen(const char *buf, size_t count);
	ssize_t readline(char *buf, size_t len);

private:
	ssize_t recv_peek(char *buf, size_t len);

	const int sockfd_;

};

#endif //SOCKETIO_H


