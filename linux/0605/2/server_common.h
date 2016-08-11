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

#define DOWN_PATH "/home/luolizhi/Downloads"
#define SIZE 1024

int recvn(int sfd,char* buf,int len);
int sendn(int sfd,char* buf,int len);
void showdir(int clientfd,const char* name);
#endif


