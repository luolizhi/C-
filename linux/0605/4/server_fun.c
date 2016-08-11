#include"server_common.h"

void socket_init(int* fd_listen,char* ip,char* port)
{
	//socket
	*fd_listen = socket(AF_INET,SOCK_STREAM,0);
	MY_ASSERT(*fd_listen != -1,"socket");
	//bind
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(ip);
	serveraddr.sin_port = htons(atoi(port));
	MY_ASSERT(bind(*fd_listen,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr))!=-1,"bind");

	//listen
	MY_ASSERT(listen(*fd_listen,10) != -1,"listen");


}

void epoll_init(int* epoll_fd,int sfd)
{
	*epoll_fd = epoll_create(1);
	MY_ASSERT(*epoll_fd != -1, "epoll_fd");

	//epoll_ctl
	struct epoll_event my_event;
	memset(&my_event,0,sizeof(my_event));
	my_event.events = EPOLLIN;
	my_event.data.fd = sfd;

	MY_ASSERT(epoll_ctl(*epoll_fd,EPOLL_CTL_ADD,sfd,&my_event)==0,"epoll ctl");
}

/*
int epoll_wait_ready(int epoll_fd, sttuct epoll_event *events)
{
	int clientfd;
	int ready_events, index;
	
	struct epoll_event my_event, my_events[MAX];	//MAX = 65536
	memset(&my_event,0,sizeof(my_event));
	

	struct sockaddr_in clientaddr;
	socklen_t clientlen = sizeof(clientaddr);
	
	return ready_events;
}
*/


int recvn(int sfd,char* buf,int len)
{
	int recv_n;
	int recv_sum=0;
	while(recv_sum < len)
	{
		recv_n = recv(sfd,buf+recv_sum,len-recv_sum,0);
		recv_sum +=recv_n;
	}
	return recv_sum;
}
int sendn(int sfd,char* buf,int len)
{
	int send_sum=0;
	int send_ret;
	while(send_sum < len)
	{
		send_ret = send(sfd,buf+send_sum,len-send_sum,0);
		send_sum += send_ret;
	}
	return send_sum;
}


void showdir(int clientfd,const char* name)
{
	DIR* dir = opendir(name);
	char buf[SIZE]="";
	struct dirent* pent;
	while((pent=readdir(dir))!=NULL)
	{
		if(strcmp(pent->d_name,".")==0 || strcmp(pent->d_name,"..")==0)
		{
			continue;
		}
		strcat(buf,"\n");
		strcat(buf,pent->d_name);
	}
	send(clientfd,buf,strlen(buf),0);

}
