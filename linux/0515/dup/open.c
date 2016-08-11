#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{
	int fd = open("text.txt",O_RDWR|O_CREAT,0755);
	if (-1 == fd)
	{
		printf("open fail\n");
	}
	int fd1;
	fd1=dup(fd);
	printf("\n");
	close(fd);
	printf("fd1 is %d\n",fd1);
	int i=1;
	write();
	return 0;



}
