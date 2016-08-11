#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void handle(int signum)
{

	printf("recive a signal:%d\n",signum);
}


int main(int argc, char* argv[])//first
{
	int flag = atoi(argv[1]);	//1 parent run first,
	pid_t pid = fork();
	if(pid == 0)	//child
	{
		if(flag == 1)
		{
			sleep(3);
		}
		kill(getppid(),SIGUSR1);

		exit(1);	
	}
	
	if(flag == 2)
	{
		sleep(3);
	}
	signal(SIGUSR1,handle);
	wait(NULL);


	return 0;
}
