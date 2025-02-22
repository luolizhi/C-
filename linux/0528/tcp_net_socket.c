#include "tcp_net_socket.h"

int tcp_init(const char*ip, int port)
{
	//socket
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd == -1)
	{
		perror("socket");
		exit(1);
	}
	
	//bind
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip);	//inet_aton

	if(bind(sfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr))==-1)
	{
		perror("bind");
		close(sfd);
		exit(1);
	}
	
	//listen
	if(listen(sfd,10) == -1){
		perror("listen");
		exit(1);
	}
	return sfd;
}

int tcp_accept(int sfd)	//server accept
{
	struct sockaddr_in  clientaddr;	//sockaddr_in ???
	memset(&clientaddr,0,sizeof(struct sockaddr));
	int addrlen = sizeof(struct sockaddr);
	int new_fd = accept(sfd,(struct sockaddr*)&clientaddr,&addrlen);
	if(new_fd == -1)
	{
		perror("accept");
		close(sfd);
		exit(1);
	}
	printf("%s %d\nsuccess connect...\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
	return new_fd;
}


int tcp_connect(const char* ip, int port)
{
	//socket
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd == -1)
	{
		perror("socket");
		exit(1);
	}
	//connect
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(struct sockaddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip);
	if(connect(sfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr))==-1)	
	{
		perror("connect");
		close(sfd);
		exit(1);	
	}
	return sfd;
}


void signalhandler(void)
{
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset,SIGINT);
	sigaddset(&sigset,SIGQUIT);
	sigprocmask(SIG_BLOCK,&sigset,NULL);
}






