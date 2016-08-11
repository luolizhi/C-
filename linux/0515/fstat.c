#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fd=open(argv[1],O_RDONLY);
	struct stat lnode;
	int ret=fstat(fd,&lnode);
	if(ret!=0)
		printf("fstat is error\n");
	printf("the node is %d\n",lnode.st_nlink);

	return 0;
}
