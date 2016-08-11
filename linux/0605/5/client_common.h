#ifndef __CLIENT_COMMON__
#define __CLIENT_COMMON__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>
#include<fcntl.h>

#define SIZE 1024
#define MAX	65535
#define DOWN_PATH "/home/luolizhi/Downloads"

#define MY_ASSERT(flag,msg) do{\
	(flag)||(printf("%s\n",msg),exit(1),0);\
}while(0)

#endif
