#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8888
#define IP "192.168.1.153"

int main(int argc,char* argv[])
{
	//socket
	int sfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sfd == -1)
	{
		perror("socket");
		exit(1);
	}
	
	
	struct sockaddr_in peeraddr;
	peeraddr.sin_family = AF_INET;
	peeraddr.sin_port = htons(PORT);
	peeraddr.sin_addr.s_addr = inet_addr(IP);
	/*
	if(-1 == bind(sfd,(struct sockaddr*)&addr,sizeof(struct sockaddr)))
	{
		perror("bind");
		exit(1);
	}
	*/
	
	
	//sendto
	char *p ="ni hao";
	sendto(sfd,p,strlen(p),0,(struct sockaddr*)&peeraddr,sizeof(peeraddr));
	//recvfrom
	int recv_ret;
	struct sockaddr_in addr;
	char buf[1024]="";
	socklen_t len=sizeof(addr);
	recv_ret=recvfrom(sfd,buf,1023,0,(struct sockaddr*)&addr,&len);
	if(recv_ret == -1)
	{
		perror("recvfrom");
		exit(1);
	}
	printf("ip:%s,port:%d\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
	printf("msg:%s\n",buf);


	close(sfd);


	return 0;
}










