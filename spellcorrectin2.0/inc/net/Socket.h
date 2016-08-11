/*************************************************************************
	> File Name: Socket.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 06 Sep 2015 04:03:00 PM CST
 ************************************************************************/

#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "NonCopyable.h"
#include "InetAddress.h"

class Socket :private NonCopyable
{
public:
	explicit Socket(int sockfd);
	Socket();
	~Socket();
	int fd() const {return sockfd_; }
	bool init(int protocol, InetAddress &addr);
	int accept();

	void shutdownWrite();
	//static
	static InetAddress getLocalAddress(int sockfd);
	static InetAddress getPeerAddress(int sockfd);

	int get_sockfd() const;

private:
	void bindAddress(const InetAddress &addr);
	void listen();
	void setTcpNoDelay(bool on);
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void setKeepAlive(bool on);


private:
	int sockfd_;
};

#endif  // SOCKET_H
