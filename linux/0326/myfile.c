#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	int fd = open(argv[1],O_WRONLY);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}
	ftruncate(fd,1024);
	return 0;
}
