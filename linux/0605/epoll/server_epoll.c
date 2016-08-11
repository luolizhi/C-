#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/epoll.h>

#define MY_ASSERT(flag,msg) do{\
	(flag)||(printf("%s\n",msg),exit(1),0);\
}while(0)


int main(int argc,char* argv[])	//ip port
{
	if(argc != 3)
	{
		printf("server ip port\n");
		exit(1);
	}
	//socket
	int fd_listen = socket(AF_INET,SOCK_STREAM,0);
	MY_ASSERT(fd_listen!=-1,"socket");
	//bind
	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);
	seraddr.sin_port = htons(atoi(argv[2]));

	MY_ASSERT(0 == bind(fd_listen,(struct sockaddr*)&seraddr,sizeof(struct sockaddr)),"bind");

	//listen
	MY_ASSERT(0 == listen(fd_listen,10),"listen");

	//epoll
	int epoll_fd, fd_client;
	MY_ASSERT(-1 != (epoll_fd = epoll_create(1)),"epoll create");

	struct epoll_event my_event, my_events[65535];
	int ready_events,index;
	char buf[1024]="";
	memset(&my_event,0,sizeof(my_event));
	my_event.data.fd = fd_listen;
	my_event.events = EPOLLIN;

	struct sockaddr_in peeraddr;
	socklen_t len=sizeof(peeraddr);

	MY_ASSERT(0==epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_listen,&my_event),"epoll ctl");

	while(1)
	{
		memset(my_events,0,sizeof(my_events));
		ready_events = epoll_wait(epoll_fd,my_events,65535,-1);
		for(index=0;index<ready_events;index++)
		{
			if(my_events[index].events & EPOLLIN && my_events[index].data.fd == fd_listen)
			{
				//accept
				fd_client = accept(my_events[index].data.fd,(struct sockaddr*)&peeraddr,&len);
				printf("client ip:%s,port:%d on!\n",inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port));

				memset(&my_event,0,sizeof(my_event));
				my_event.data.fd = fd_client;
				my_event.events = EPOLLIN;

				MY_ASSERT(0==epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_client,&my_event),"epoll ctl client");
			}else if(my_events[index].events & EPOLLIN)
			{
				//recv
				int recvn;
				memset(buf,0,sizeof(buf));
				recvn = recv(my_events[index].data.fd,buf,sizeof(buf),0);
	
				if(recvn == 0)
				{
					printf("%u exit\n",getpid());
					MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_DEL,my_events[index].data.fd,NULL)==0,"epoll ctl del");
					continue;
				}
				printf("recv:%s\n",buf);
			}

		}
	}

	return 0;
}
