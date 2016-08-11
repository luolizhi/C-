#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("fork");
		exit(1);
	}
	else if(pid==0)
	{
		//child
		printf("child::pid:%d,ppid:%d\n",getpid(),getppid());
		sleep(15);
		exit(1);
	}
	else
	{
		//parent
		printf("parent::pid:%d,ppid:%d\n",getpid(),getppid());	
		int ret;
		pid_t child_pid;
		printf("parent waiting ....\n");
		child_pid = wait(&ret);
		printf("%d exit,%04x\n",child_pid,ret);
	}

}
