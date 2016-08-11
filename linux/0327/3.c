#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FIFO_31 "./31.fifo"
#define FIFO_13 "./13.fifo"
#define FIFO_32 "./32.fifo"
#define FIFO_23 "./23.fifo"

//3:rite 1,3recive
int main(int argc, char* argv[])
{
	int fd_13=open(FIFO_13,O_RDONLY);
	int fd_31=open(FIFO_31,O_WRONLY);
	int fd_23=open(FIFO_23,O_RDONLY);
	int fd_32=open(FIFO_32,O_WRONLY);
	char msg[1024];
	int readn;
/*
	if(fd_32==-1||fd_23==-1||fd_13==-1||fd_31==-1)
	{
		perror("open");
		exit(1);
	}
*/
	printf("13:%d,31:%d,23:%d,32:%d\n",fd_13,fd_31,fd_23,fd_32);
	while(1){
		//recive from 1
		memset(msg,0,sizeof(msg));
		readn=read(fd_13,(msg),strlen(msg));
		printf("from 1: %d: %s\n",readn,msg);

		//recive from 2
		memset(msg,0,sizeof(msg));
		readn=read(fd_23,(msg),strlen(msg));
		printf("from 2: %d: %s\n",readn,msg);
		
		//send to  1, 2
		printf(">>:\n");
		memset(msg,0,sizeof(msg));
		fgets(msg,sizeof(msg),stdin);//<->read()
		write(fd_31,msg,strlen(msg));
		write(fd_32,msg,strlen(msg));

	
	}

	return 0;
}

