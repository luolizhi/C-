#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
int main()
{
	printf("my pid is %d\n",getpid());
	kill(2652,SIGINT);
	return 0;
}
