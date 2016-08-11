#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MAXPROCESS 65535
#define SLEEPTIME 60

int main(int argc,char* argv[])
{
	pid_t pid;
	int count = 0;
	int maxprocess=MAXPROCESS;
	if(argc ==2)
	{
		maxprocess = atoi(argv[1]);
	}
	for(count=0;count<maxprocess;count++)
	{
		pid = fork();
		if(pid < 0)
		{
			perror("fork error");
			exit(1);
		}else if(pid == 0)
		{
			printf("child %d start\n",count);
			sleep(SLEEPTIME);
			printf("child %d end\n",count);
			exit(0);
		}
		printf("parent:creat %d child\n",count);
	}

	for(count=0;count<MAXPROCESS;count++)
	{
		wait(NULL);
	}


	return 0;
}
