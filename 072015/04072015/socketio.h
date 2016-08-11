/*************************************************************************
  > File Name: socketio.h
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Sat 04 Jul 2015 11:16:36 AM CST
 ************************************************************************/

#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

#include "noncopyable.h"
#include<sys/types.h>

namespace lukey
{
	class SocketIO : public Noncopyable
	{
		public:
			explicit SocketIO(int sockfd)
				: sockfd_(sockfd)
			{}

			ssize_t readn(char *buf, size_t count);
			ssize_t writen(const char *buf, size_t count);
			ssize_t readline(char *usrbuf, size_t maxlen);
		private:
			ssize_t recv_peek(char *buf, size_t len);
			const int sockfd_;
	};

}//end of namespace lukey

#endif
