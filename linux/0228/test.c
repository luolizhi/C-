#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])	//filename
{
	int fds[2];	//0 read 1 write
	pipe(fds);
	if(fork()==0)
	{
		int fd_recv;
		char buf[1024]="";
		close(fds[1]);
		read(fds[0],&fd_recv,4);
		printf("child:file_fd:%d\n",fd_recv);
		if(-1 == read(fd_recv,buf,1024))
		{
			printf("child read error\n");
		}else
		{
			printf("read:%s\n",buf);
		}

		exit(1);
	}
	else
	{
		close(fds[0]);
		int fd = open(argv[1],O_RDONLY);		
		printf("parent:file_fd:%d\n",fd);
		write(fds[1],&fd,4);
		wait(NULL);
	}
	return 0;
}
