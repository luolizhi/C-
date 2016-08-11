#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int fd=open(argv[1],O_RDONLY);
	char buf[100];
	while(memset(buf,0,sizeof(buf)),read(fd,buf,50)!=0)
	{
		fputs(buf,stdout);
	}

	return 0;
}
