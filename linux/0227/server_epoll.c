#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define MY_ASSERT(flag,msg) \
	do {\
		(flag) || ((printf("%s\n",msg)),exit(1),0);\
	}while(0)

int main(int argc, char* argv[])	//ip  port
{
	if(argc < 3)
	{
		printf("wrong argc(ip  port)\n");
	}
	
	//printf("ip:%s\nport:%s\n",argv[1],argv[2]);

	int fd_listen, fd_client;
	MY_ASSERT((fd_listen=socket(AF_INET,SOCK_STREAM,0))!= -1,"socket init");

	//bind
	struct sockaddr_in seraddr;
	memset(&seraddr,0,sizeof(seraddr));
	
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(argv[2]));
	seraddr.sin_addr.s_addr=inet_addr(argv[1]);
	//MY_ASSERT(bind(fd_listen,(struct sockaddr*)&seraddr,sizeof(seraddr))==0,"bind failed");
	
	bind(fd_listen,(struct sockaddr*)&seraddr,sizeof(struct sockaddr));


	//MY_ASSERT(listen(fd_listen,10)==0,"listen");
	listen(fd_listen,10);
	//epoll
	int epoll_fd;
	MY_ASSERT((epoll_fd = epoll_create(10))!=-1,"epoll_creat");

	struct epoll_event my_event, my_events[1024];
	char buf[1024];
	int ready_events;

	my_event.events = EPOLLIN;
	my_event.data.fd = fd_listen;
	
	//MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_listen,&my_event)==0,"epoll ctl");
	epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_listen,&my_event);

	while(1)
	{
		memset(my_events,0,sizeof(my_events));
		ready_events=epoll_wait(epoll_fd,my_events,1024,-1);
		int index;
		for(index=0;index<ready_events;index++)
		{
			if(my_events[index].events & EPOLLIN && my_events[index].data.fd==fd_listen)
			{
				fd_client = accept(my_events[index].data.fd,NULL,NULL);
				printf("a client connect.\n");

				memset(&my_event,0,sizeof(my_event));
				my_event.events = EPOLLIN;
				my_event.data.fd = fd_client;

				//MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_client,&my_event)==0,"epoll ctl client");
				epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_client,&my_event);
			}
			else if(my_events[index].events & EPOLLIN)
			{
				memset(buf,0,1024);

				if(recv(my_events[index].data.fd,buf,sizeof(buf),0)==0)
				{
					printf("a clienr exit\n");
					epoll_ctl(epoll_fd,EPOLL_CTL_DEL,my_events[index].data.fd,NULL);
				}else

				printf("recv from client:%s\n",buf); 
			}
		}
	}





	return 0;
}










