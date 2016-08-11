#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FIFO_12 "./12.fifo"
#define FIFO_21 "./21.fifo"
#define FIFO_13 "./13.fifo"
#define FIFO_31 "./31.fifo"

//1:rite 2,3recive
int main(int argc, char* argv[])
{
	int fd_12=open(FIFO_12,O_WRONLY);//1-2
	int fd_21=open(FIFO_21,O_RDONLY);//2-1
	int fd_13=open(FIFO_13,O_WRONLY);//1-3
	int fd_31=open(FIFO_31,O_RDONLY);//3-1
	char msg[1024];
	int readn;
/*
	if(fd_12==-1||fd_21==-1||fd_13==-1||fd_31==-1)
	{
		perror("open");
		exit(1);
	}
*/
	printf("12:%d,21:%d,13:%d,31:%d\n",fd_12,fd_21,fd_13,fd_31);
	while(1){
		//send to  2, 3
		printf(">>:\n");
		memset(msg,0,sizeof(msg));
		fgets(msg,sizeof(msg),stdin);//<->read()
		write(fd_12,msg,strlen(msg));
		write(fd_13,msg,strlen(msg));

		//recive from 2
		memset(msg,0,sizeof(msg));
		readn=read(fd_21,(msg),strlen(msg));
		printf("from 2: %d: %s\n",readn,msg);

		//recive from 3
		memset(msg,0,sizeof(msg));
		readn=read(fd_31,(msg),strlen(msg));
		printf("from 3: %d: %s\n",readn,msg);
	
	}

	return 0;
}

