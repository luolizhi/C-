#include "pool_pthread.h"
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<pthread.h>
#define DOWN_PATH "/home/luolizhi/Downloads"

void show(int sfd);
void* handle(void* arg);
void handle_request(int sfd);
int recvn(int sfd,char* buf, int len);
int sendn(int sfd,char* buf, int len);


int main(int argc, char* argv[])	//capacity  num ip port
{
	if(argc != 5)
	{
		printf("wrong argc\n(capacity num ip port)\n");
		exit(1);
	}
	printf("0:%s\n1:%s\n2:%s\n3:%s\n4:%s\n",argv[0],argv[1],argv[2],argv[3],argv[4]);
	//fd_listen
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	//printf("socket 00\n");
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	//printf("socket 11\n");

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr((argv[3]));
	server_address.sin_port = htons(atoi(argv[4]));
	server_len =  sizeof(server_address);
	//printf("pool_init 111\n");
	bind(server_sockfd,(struct sockaddr*)&server_address,server_len);

	if(-1==listen(server_sockfd,10))
	{
		perror("listen");
		exit(1);
	}


	//client_len = sizeof(client_address);

	//thread_pool
	threadspool_t mypool;
	//memset(&mypool,0,sizeof(mypool));
	pool_init(&mypool,atoi(argv[1]),atoi(argv[2]),handle);
	//printf("pool_init 11111\n");
	pool_on(&mypool);
	//printf("pool_on\n");

	char buf[128];

	while(1){
		fd_set rds;
		FD_ZERO(&rds);
		FD_SET(server_sockfd,&rds);

		struct timeval tm;
		tm.tv_sec = 3;
		tm.tv_usec = 0;

		printf("while(1)\n");

		if(select(1024,&rds,NULL,NULL,&tm)==0)
		{
			continue;	//the code below won't execute
		}
		printf("select begin\n");

		if(FD_ISSET(server_sockfd,&rds))
			client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_address,&client_len);

		printf("%s:%d,connect!\n",inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port));

		//init a task;
		elem_t val = client_sockfd;
		pool_put(&mypool,val);
	}
	printf("while end\n");
	pool_off(&mypool);
	pool_destroy(&mypool);
	return 0;
}


int recvn(int sfd,char* buf, int len)
{
	int recv_sum = 0;
	int recv_ret;
	while(recv_sum < len)
	{
		recv_ret = recv(sfd,(char*)buf+recv_sum,len-recv_sum,0);
		recv_sum += recv_ret;
	}

	return recv_sum;
}

int sendn(int sfd,char* buf, int len)
{
	int send_sum = 0;
	int send_ret;
	while(send_sum < len)
	{
		send_ret = send(sfd,(char*)buf+send_sum,len-send_sum,0);
		send_sum += send_ret;
	}
	return send_sum;
}
void handle_request(int sfd)
{
	printf("handle_request\n");
	show(sfd);
	char full_path[256]="";
	char target_file[128] = "";
	int len;
	recv(sfd,&len,4,0);	//recv lenth of sending file
	recvn(sfd,target_file,len);
	printf("down file:%s\n",target_file);
	sprintf(full_path,"%s/%s\n",DOWN_PATH,target_file);
	//read 
	printf("full_path:%s\n",full_path);

	full_path[strlen(full_path)-1]='\0';
	FILE* fp = fopen(full_path,"r");

	//file not exsit send -1 to client
	if(fp == NULL)
	{
		perror("fopen..");
		len=-1;
		send(sfd,&len,4,0);
		close(sfd);
		return;
	}
	len =1;
	send(sfd,&len,4,0);


	char msg[1024];
	//int len;
	while(memset(msg,0,1024),fgets(msg,1024,fp)!=NULL)
	{
		len=strlen(msg);
		send(sfd,&len,4,0);

		sendn(sfd,msg,len);
	}
	len = 0;
	send(sfd,&len,4,0);
	close(sfd);
}
void show(int sfd)
{
	printf("show");
	DIR* pdir;
	pdir = opendir(DOWN_PATH);
	if(pdir == NULL)
	{
		perror("opendir");
		exit(1);
	}

	struct dirent* pent;
	char buf[1024]="";
	int len;
	while((pent = readdir(pdir)) != NULL)
	{
		if(strcmp(".",pent->d_name)==0 || strcmp("..",pent->d_name)==0)
		{
			continue;
		}
		strcat(buf,"\n");
		strcat(buf,pent->d_name);
	}

	len = strlen(buf);
	send(sfd,&len,4,0);
	sendn(sfd,buf,len);


}

void* handle(void* arg)
{
	//pool_get
	//excute_task
	pthreadspool_t ppool = (pthreadspool_t)arg;
	elem_t fd_client;
	while(1)
	{

		pool_get(ppool,&fd_client);
		handle_request(fd_client);
		close(fd_client);
	}

}
