#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h> //read

int main(int argc, char *argv[])
{
	int fd=open(argv[1],O_RDONLY);
	int readn;	
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}	

	char buf[400]="";
	while(memset(buf,0,sizeof(buf)),(readn=read(fd,buf,sizeof(buf)-1))>0)
	{
	printf("%s\n",buf);
	printf("%d\n",readn);
	}
	close(fd);
	return 0;
}

