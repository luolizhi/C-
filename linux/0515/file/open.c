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
	int a[10], i,ret,b[25];
	for(i=0;i<10;i++)
	{
		a[i]=i;
	}
	ret=write(fd,a,10*sizeof(int));
	printf("ret is %d\n",ret);
	ftruncate(fd,100);
	read(fd,b,25*sizeof(int));
	for(i=0;i<25;i++)
		printf("%4d",b[i]);
	printf("\n");
	close(fd);
	return 0;



}
