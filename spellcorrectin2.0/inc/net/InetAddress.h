/*************************************************************************
	> File Name: InetAddress.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sat 05 Sep 2015 09:10:33 PM CST
 ************************************************************************/

#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__

#include <string>
#include <netinet/in.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;

class InetAddress //copyable
{
public:
	explicit InetAddress(uint16_t port);
	InetAddress(const std::string &ip, uint16_t port);
	InetAddress(const struct sockaddr_in &addr);

	//set get
	void setSockAddrInet(const struct sockaddr_in &addr)
	{
		addr_ = addr;
	}

	const struct sockaddr_in *getSockAddrInet() const
	{
		return &addr_;
	}

	//ip port
	std::string toIp() const;
	uint16_t toPort() const;

private:
	struct sockaddr_in addr_;
};

#endif


