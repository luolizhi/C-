#include"server_common.h"

int main(int argc, char* argv[])	//ip port
{
	if(argc != 3)
	{
		printf("EXE IP PORT\n");
		exit(1);
	}
	//socket
	int serverfd = socket(AF_INET,SOCK_STREAM,0);
	if(serverfd == -1)
	{
		perror("socket");
		exit(1);
	}

	//bind
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = htons(atoi(argv[2]));

	if(-1 == bind(serverfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr)))
	{
		perror("bind");
		exit(1);
	}

	//listen
	if(-1 == listen(serverfd,10))
	{
		perror("listen");
		exit(1);
	}


	//epoll
	int epoll_fd = epoll_create(1);
	MY_ASSERT(epoll_fd!=-1,"epoll_fd");

	//epoll_ctl
	struct epoll_event my_event, my_events[MAX];	//MAX = 65536
	memset(&my_event,0,sizeof(my_event));
	my_event.events = EPOLLIN;
	my_event.data.fd = serverfd;

	MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,serverfd,&my_event)==0,"epoll ctl");


	int clientfd;
	int ready_events, index;

	struct sockaddr_in clientaddr;
	socklen_t clientlen = sizeof(clientaddr);


	//epoll_wait
	while(1)
	{
		//printf("while\n");
		memset(my_events,0,sizeof(my_events));
		ready_events = epoll_wait(epoll_fd,my_events,MAX,-1);
		//printf("ready ok\n");
		for(index=0;index<ready_events;index++)
		{
			if(my_events[index].events & EPOLLIN && my_events[index].data.fd==serverfd)
			{
				//accept
				clientfd = accept(serverfd,(struct sockaddr*)&clientaddr,&clientlen);
				MY_ASSERT(clientfd != -1,"ACCEPT");
				printf("client: ip:%s,port:%d on\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
				
				showdir(clientfd,DOWN_PATH);

				//epoll_ctl_add clientfd
				memset(&my_event,0,sizeof(my_event));
				my_event.events = EPOLLIN;
				my_event.data.fd = clientfd;

				MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,clientfd,&my_event)==0,"epoll ctl clientfd");
			}
			else if(my_events[index].events & EPOLLIN )
			{
				//recv filename and send the file

				int recvnum;
				char recv_buf[SIZE] = "";
				char FULL_PATH[SIZE] = "";

				recvnum = recv(clientfd,recv_buf,sizeof(recv_buf)-1,0);
				if(recvnum == 0)	//client exit
				{
					printf("a client exit\n");
					memset(&my_event,0,sizeof(my_event));
					my_event.events = EPOLLIN;
					my_event.data.fd = clientfd;

					MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_DEL,my_events[index].data.fd,&my_event)==0,"epoll ctl clientfd delet");

				}
				else
				{
					sprintf(FULL_PATH,"%s/%s",DOWN_PATH,recv_buf);
					FULL_PATH[strlen(FULL_PATH)-1] = '\0';
					printf("download file:%s\n",FULL_PATH);

					//open the file
					int file_fd = open(FULL_PATH,O_RDONLY);
					MY_ASSERT(file_fd != -1,"open file");

					char send_buf[MAX] = "";
					size_t readnum;
					
					while(memset(send_buf,0,sizeof(send_buf)),(readnum=read(file_fd,send_buf,sizeof(send_buf)))!=0)
					{
						sendn(my_events[index].data.fd,send_buf,readnum);
						printf("readnum:%d\n",readnum);
					}
				}		
			}
		}
	}

	close(clientfd);
	close(serverfd);
	return 0;
}

