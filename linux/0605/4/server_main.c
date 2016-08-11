#include"server_common.h"

int main(int argc, char* argv[])	//ip port
{
	if(argc != 3)
	{
		printf("EXE IP PORT\n");
		exit(1);
	}
	//socket	
	int serverfd;
	socket_init(&serverfd,argv[1],argv[2]);

	//epoll
	int epoll_fd;
	epoll_init(&epoll_fd,serverfd);



	int clientfd;
	int ready_events, index;
	struct epoll_event my_event,my_events[MAX];	//MAX = 65536

	struct sockaddr_in clientaddr;
	socklen_t clientlen = sizeof(clientaddr);


	//epoll_wait
	while(1)
	{
		memset(my_events,0,sizeof(my_events));
		ready_events = epoll_wait(epoll_fd,my_events,MAX,-1);
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

				if(fork()==0)
				{
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
						//MY_ASSERT(file_fd != -1,"open file");
						if(file_fd == -1)
						{
							char* p = "10000";
							send(my_events[index].data.fd, p, strlen(p),0);
							printf("the file: %s not exit!\n",FULL_PATH);
							continue;
						}else
						{
							char send_buf[MAX] = "";
							size_t readnum;

							while(memset(send_buf,0,sizeof(send_buf)),(readnum=read(file_fd,send_buf,sizeof(send_buf)))!=0)
							{
								int sendm=sendn(my_events[index].data.fd,send_buf,readnum);
								printf("readnum:%d;sendn:%d\n",readnum,sendm);
							}
						}
					}		
				}
				else
				{
					continue;
				}
			}
		}
	}

	close(clientfd);
	close(serverfd);
	return 0;
}

