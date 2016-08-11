/*************************************************************************
	> File Name: client.c
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sun 12 Jul 2015 08:31:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define ERR_EXIT(msg)	\
	do{\
		perror(msg);\
		exit(EXIT_FAILURE);\
	}while(0);

void do_service(int sockfd);

int main(int argc, char *argv[])
{
	int peerfd = socket(PF_INET, SOCK_STREAM, 0);
	if(-1 == peerfd)
		ERR_EXIT("socket");


	struct sockaddr_in addr;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("192.168.1.153");
	addr.sin_port = htons(9999);
	socklen_t len = sizeof addr;
	if(connect(peerfd, (struct sockaddr*)&addr, len) == -1)
		ERR_EXIT("connect");

	do_service(peerfd);
	
	return 0;
}

void do_service(int sockfd)
{
	char recvbuf[1024] = {0};
	char sendbuf[1024] = {0};

	while(1)
	{
		fgets(sendbuf, sizeof sendbuf, stdin);
		write(sockfd, sendbuf, strlen(sendbuf));

		//read
		int nread = read(sockfd, recvbuf, sizeof recvbuf);
		if(-1 == nread)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("read");
		}
		else if(nread == 0)
		{
			printf("server close\n");
			close(sockfd);
			exit(EXIT_SUCCESS);
		}

		printf("recieve msg : %s\n", recvbuf);

		memset(recvbuf, 0, sizeof recvbuf);
		memset(sendbuf, 0, sizeof sendbuf);
	}
}
