/*************************************************************************
  > File Name: inetaddress.h
  > Author: lukey
  > Mail: lukey123@foxmail.com 
  > Created Time: Sat 04 Jul 2015 11:16:36 AM CST
 ************************************************************************/

#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__

#include<string>
#include<netinet/in.h>

namespace lukey
{
	class Inetaddress
	{
		public:
			explicit Inetaddress(uint16_t port);
			Inetaddress(const struct sockaddr_in &addr);
			Inetaddress(const std::string &ip, uint16_t port);//构造函数

			//set get
			void setSockAddrInet(const struct sockaddr_in &addr)
			{
				addr_ = addr;
			}

			const struct sockaddr_in * getSockAddrInet()const
			{
				return &addr_;
			}
			//ip port 
			std::string toIp() const;
			uint16_t toPort() const;

		private:
			struct sockaddr_in addr_;
	};

}//end of namespace lukey

#endif
