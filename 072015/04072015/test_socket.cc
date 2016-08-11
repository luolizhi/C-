/*************************************************************************
	> File Name: test_socket.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 12 Jul 2015 08:20:11 PM CST
 ************************************************************************/

#include"inetaddress.h"
#include"socket.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	lukey::Inetaddress addr("192.168.1.153", 9999);

	lukey::Socket sock;
	sock.setReusePort(true);
	sock.setReuseAddr(true);

	sock.bind(addr);
	sock.listen();

	int peerfd = sock.accept();

	while(1)
	{
		char recvbuf[1024] = {0};
		::read(peerfd, recvbuf, sizeof(recvbuf));
		printf("receive msg : %s\n", recvbuf);
		::write(peerfd, recvbuf, strlen(recvbuf));
	}

	return 0;
}



