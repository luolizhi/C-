/*************************************************************************
	> File Name: server.c
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sat 04 Jul 2015 10:07:45 AM CST
 ************************************************************************/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>


class

class InetAddress
{

};

int main(void)
{
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	if (-1 == listenfd)
	{
		perror("socket");
		return EXIT_FAILURE;
	}

	struct sockadd_in seraddr;
	memset(seraddr,0,sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(9999);
	seraddr.sin_addr.s_addr = inet_addr("192.168.1.153");

	int on = 1;
	if(-1 == setsockopt(listenfd,SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)))
	{
		perror("setsockopt");
		close(listenfd);
		return EXIT_FAILURE;
	}

	if(-1 == bind(listenfd,(struct sockaddr*)&seraddr,sizeof(struct sockaddr*)))
	{
		perror("bind");
		return EXIT_FAILURE;
	}
	
	if(listen(listenfd, 10) < 0)
	{
		perror("listen");
		close(listenfd);
		return EXIT_FAILURE;
	}

	int peerfd = accept(listen, NULL, NULL);

	char buf[1024];
	memset(buf, 0, sizeof(buf));
	int nread = read(peerfd, buf, 1024);

	int nwrite = write(peerfd, buf, 1024);
}

