#ifndef __SERVER_COMMON__
#define __SERVER_COMMON__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
						//socket
#include<sys/types.h>
#include<sys/socket.h>
						//inet
#include<netinet/in.h>
#include<arpa/inet.h>
						//FILE
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
						//opendir
#include<sys/types.h>
#include<dirent.h>

#include<sys/epoll.h>

#define DOWN_PATH "/home/luolizhi/Downloads"
#define SIZE 1024
#define MAX 65536
#define MY_ASSERT(flag,msg) do{\
	(flag)||(printf("%s\n",msg),exit(1),0);\
}while(0)




int recvn(int sfd,char* buf,int len);
int sendn(int sfd,char* buf,int len);
void showdir(int clientfd,const char* name);
#endif


