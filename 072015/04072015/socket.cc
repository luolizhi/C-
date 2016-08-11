/*************************************************************************
	> File Name: socket.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 07 Jul 2015 11:38:51 AM CST
 ************************************************************************/

#include "socket.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>


namespace lukey
{
	Socket::Socket()
	{
		sockfd_ = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(-1 == sockfd_)
		{
			perror("create socket");
			exit (EXIT_FAILURE);
		}
	}

	Socket::~Socket()
	{
		::close(sockfd_);
	}


	void Socket::bind(const Inetaddress &addr)
	{
		if(-1 == ::bind(sockfd_, (struct sockaddr*)addr.getSockAddrInet(),sizeof(addr)))
		{
			fprintf(stderr, "bind");
			exit(EXIT_FAILURE);
		}
	}

	void Socket::listen()
	{
		if(-1 == ::listen(sockfd_, SOMAXCONN))
		{
			fprintf(stderr, "listen");
			exit(EXIT_FAILURE);
		}
	}

	int Socket::accept()
	{
		int fd = ::accept(sockfd_, NULL, NULL);
		if(-1 == fd)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		return fd;
	}

	void Socket::shutdownWrite()
	{
		if(-1 == ::shutdown(sockfd_, SHUT_WR))
		{
			perror("shutdown");
			exit(EXIT_FAILURE);
		}
	}

	void Socket::setReuseAddr(bool on)
	{
		int optval = on ? 1 : 0;
		if(::setsockopt(sockfd_,
						SOL_SOCKET,
						SO_REUSEADDR,
						&optval,
						static_cast<socklen_t>(sizeof(optval))) == -1)
		{
			perror("set_addr_reuse");
			exit(EXIT_FAILURE);
		}
	}

	void Socket::setReusePort(bool on)
	{
#ifdef SO_REUSEPORT
		int optval = on ? 1 : 0;
		int ret = ::setsockopt(sockfd_,SOL_SOCKET, SO_REUSEPORT,
				&optval, static_cast<socklen_t>(sizeof optval));
		if(ret < 0)
		{
			perror("setReusePort");
			exit(EXIT_FAILURE);
		}
#else
		if(on)
		{
			fprintf(stderr, "SO_REUSEPORT is not supported");
		}
#endif
	}

	//static
	Inetaddress Socket::getLocalAddr(int sockfd)
	{
		struct sockaddr_in addr;
		socklen_t len = sizeof addr;
		if(-1 == ::getsockname(sockfd, (struct sockaddr*)&addr, &len))
		{
			perror("get_local_addr");
			exit(EXIT_FAILURE);
		}

		return Inetaddress(addr);
	}

	Inetaddress Socket::getPeerAddr(int sockfd)
	{
		struct sockaddr_in addr;
		socklen_t len = sizeof addr;
		if(-1 == ::getpeername(sockfd, (struct sockaddr*)&addr, &len))
		{
			perror("get_peer_addr");
			exit(EXIT_FAILURE);
		}
		return Inetaddress(addr);
	}



}//end of namespace lukey


