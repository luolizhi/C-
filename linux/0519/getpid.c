#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
	
	int mypid;
	mypid = getppid();
	printf("mypid:%d\nppid:%d\n",mypid,getppid());
	return 0;

}
