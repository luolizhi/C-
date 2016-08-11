#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	pid_t pid;
	pid = fork();
	if(pid<0){
	printf("error");
	}
	//child 
	else if(pid==0){
		printf("c:::pid:%d,ppid:%d\n",getpid(),getppid());
	}
	else{
		printf("father:pid: %d,ppid:%d\n",getpid(),getppid());
	}
	sleep(1);
	return 0;

}
