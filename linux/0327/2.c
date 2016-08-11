#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FIFO_21 "./21.fifo"
#define FIFO_12 "./12.fifo"
#define FIFO_23 "./23.fifo"
#define FIFO_32 "./32.fifo"

//2:rite 1,3recive
int main(int argc, char* argv[])
{
	int fd_12=open(FIFO_12,O_RDONLY);
	int fd_21=open(FIFO_21,O_WRONLY);//2-1
	int fd_23=open(FIFO_23,O_WRONLY);
	int fd_32=open(FIFO_32,O_RDONLY);
	char msg[1024];
	int readn;
	/*
	if(fd_12==-1||fd_21==-1||fd_23==-1||fd_32==-1)
	{
		perror("open");
		exit(1);
	}
*/
	printf("12:%d,21:%d,23:%d,32:%d\n",fd_12,fd_21,fd_23,fd_32);
	while(1){
		//recive from 1
		memset(msg,0,sizeof(msg));
		readn=read(fd_12,(msg),strlen(msg));
		printf("from 1: %d: %s\n",readn,msg);
		
		//send to  1, 3
		printf(">>:\n");
		memset(msg,0,sizeof(msg));
		fgets(msg,sizeof(msg),stdin);//<->read()
		write(fd_21,msg,strlen(msg));
		write(fd_23,msg,strlen(msg));

		//recive from 1
		memset(msg,0,sizeof(msg));
		readn=read(fd_12,(msg),strlen(msg));
		printf("from 1: %d: %s\n",readn,msg);

		//recive from 3
		memset(msg,0,sizeof(msg));
		readn=read(fd_32,(msg),strlen(msg));
		printf("from 3: %d: %s\n",readn,msg);
	
	}

	return 0;
}

