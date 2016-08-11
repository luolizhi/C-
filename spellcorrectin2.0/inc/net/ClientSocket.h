/*************************************************************************
	> File Name: ClientSocket.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 06 Sep 2015 09:02:37 PM CST
 ************************************************************************/

#ifndef __CLIENTSOCKET_H__
#define __CLIENTSOCKET_H__

class InetAddress;	//前向声明？

class ClientSocket
{
public:
	ClientSocket();
	~ClientSocket();

	void init(int protocol);
	void connect(InetAddress &);
	int get_socket() const;

private:
	int sockfd_;
};




#endif


