#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{

	printf("pid:%d,ppid:%d,uid:%d,gid:%d\n",getpid(),getppid(),getuid(),getgid());
	
		int fd=open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}
	else
		printf("%d\n",fd);
	return 0;
}
