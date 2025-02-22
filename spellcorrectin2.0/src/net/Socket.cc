/*************************************************************************
	> File Name: Socket.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 01 Oct 2015 03:41:56 PM CST
 ************************************************************************/

#include "Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>


Socket::Socket(int sockfd)
	:sockfd_(sockfd)
{
}

Socket::Socket()
{}

Socket::~Socket()
{
	::close(sockfd_);
}

bool Socket::init(int protocol, InetAddress &addr)
{
	if(0 == protocol)
	{
		sockfd_ = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(-1 == sockfd_)
		{
			perror("create socket error");
			//exit(EXIT_FAILURE);	
			return false;
		}
		setTcpNoDelay(false);
		setReuseAddr(true);
		setReusePort(true);
		setKeepAlive(true);


		bindAddress(addr);
		listen();
	}else
	{
		sockfd_ = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(-1 == sockfd_)
		{
			perror("create socket error");
			//exit(EXIT_FAILURE);
			return false;
		}
	}

	return true;	
}


void Socket::bindAddress(const InetAddress &addr)
{
	if(::bind(sockfd_, (SA*)addr.getSockAddrInet(), sizeof(addr)) == -1)
	{
		fprintf(stderr, "listen address error\n");
		exit(EXIT_FAILURE);
	}
}


int Socket::accept()
{
	int fd = ::accept(sockfd_, NULL, NULL);
	if(-1 == fd)
	{
		fprintf(stderr, "accept error\n");
		exit(EXIT_FAILURE);
	}
	return fd;
}

int Socket::get_sockfd() const
{
	return sockfd_;
}

void Socket::shutdownWrite()
{
	if(-1 == ::shutdown(sockfd_, SHUT_WR))
	{
		fprintf(stderr, "shutdown error\n");
		exit(EXIT_FAILURE);
	}
}

void Socket::setTcpNoDelay(bool on)
{
	int optval = on ? 1 : 0;	//= or ==
	if(::setsockopt(sockfd_,
				IPPROTO_TCP,	
				TCP_NODELAY,
				&optval,
				static_cast<socklen_t>(sizeof optval)) == -1)
	{
		fprintf(stderr, "setTcpNoDelay error\n");
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
				static_cast<socklen_t>(sizeof optval)) == -1)
	{
		fprintf(stderr, "setReuseAddr error\n");
		exit(EXIT_FAILURE);
	}
}


void Socket::setReusePort(bool on)
{
#ifdef SO_REUSEPORT
	int optval = on ? 1 : 0;
	int ret = ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT,
			&optval, static_cast<socklen_t>(sizeof optval));
	if (ret < 0)
	{
		fprintf(stderr, "setReusePort error\n");
		exit(EXIT_FAILURE);
	}
#else
	if(on)
	{
		fprintf(stderr, "SO_REUSEPORT is not supported.\n");
	}
#endif
}

void Socket::setKeepAlive(bool on)
{
	int optval = on ? 1 : 0;
	if(::setsockopt(sockfd_,
				SOL_SOCKET,
				SO_KEEPALIVE,
				&optval,
				static_cast<socklen_t>(sizeof optval)) == -1)
	{
		fprintf(stderr, "setKeepAlive error\n");
		exit(EXIT_FAILURE);
	}
}


//static
InetAddress Socket::getLocalAddress(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof addr;
	if(::getsockname(sockfd, (SA*)&addr, &len) == -1)
	{
		fprintf(stderr, "getLocalAddress\n");
		exit(EXIT_FAILURE);
	}
	return InetAddress(addr);
}

InetAddress Socket::getPeerAddress(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof addr;
	if(::getpeername(sockfd, (SA*)&addr, &len) == -1)
	{
		fprintf(stderr, "getPeerAddress\n");
		exit(EXIT_FAILURE);
	}

	return InetAddress(addr);
}


