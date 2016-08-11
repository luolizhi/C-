/*************************************************************************
  > File Name: socket.h
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Sat 04 Jul 2015 11:16:36 AM CST
 ************************************************************************/

#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "noncopyable.h"
#include "inetaddress.h"

namespace lukey
{

	class Socket: private  Noncopyable
	{
		public:
		explicit Socket(int sockfd);//有参构造函数，只能显示调用
		Socket();//构造函数
		~Socket();//析构函数

		int fd() const { return sockfd_; }
		void bind(const Inetaddress &);
		void listen();
		int accept();

		void setReuseAddr(bool on);
		void setReusePort(bool on);

		void ready();//封装上面四个函数

		void shutdownWrite();

		static Inetaddress getLocalAddr(int sockfd);
		static Inetaddress getPeerAddr(int sockfd);

		private:
		int sockfd_;
	};
}//end of namespace lukey


#endif
