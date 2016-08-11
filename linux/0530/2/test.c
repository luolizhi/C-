#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

int cnt = 0;
void handle(int arg)
{
	//printf("pid:%d\n",getpid());
	while(waitpid(-1,NULL,WNOHANG)>0){
	cnt ++;
	printf("a child exit:%d\n",cnt);
	}
}

int main(int argc, char* argv[])
{
	signal(SIGCHLD,handle);
	int i = 30;
	while(i>0)
	{
		if(fork()==0)
		{
			exit(1);
		}
		i --;
	}
	while(1);
	return 0;
}
