/*************************************************************************
  > File Name: inetaddress.cc
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Tue 07 Jul 2015 11:00:16 AM CST
 ************************************************************************/

#include"inetaddress.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

namespace lukey
{
	Inetaddress::Inetaddress(uint16_t port)
	{
		::memset(&addr_, 0, sizeof addr_);
		addr_.sin_family = AF_INET;
		addr_.sin_addr.s_addr = INADDR_ANY;
		addr_.sin_port = htons(port);
	}

	Inetaddress::Inetaddress(const std::string &ip, uint16_t port)
	{
		::memset(&addr_, 0, sizeof addr_);
		addr_.sin_family = AF_INET;
		addr_.sin_port = htons(port);
		if(inet_aton(ip.c_str(), &addr_.sin_addr) == 0)//成功返回非零
		{
			fprintf(stderr, "ip invalid\n");
			exit(EXIT_FAILURE);
		}
	}

	Inetaddress::Inetaddress(const struct sockaddr_in &addr)
		:addr_(addr)
	{}

	std::string Inetaddress::toIp() const
	{
		return inet_ntoa(addr_.sin_addr);
	}

	uint16_t Inetaddress::toPort() const
	{
		return ntohs(addr_.sin_port);
	}


}//end of namespace lukey


