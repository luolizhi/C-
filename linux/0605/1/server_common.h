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

#define DOWN_PATH "/home/luolizhi/Downloads"
#define SIZE 1024


void recvn(int sfd,int len);
void sendn(int sfd,int len);

#endif


