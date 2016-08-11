#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int fds[2];
	if(-1==pipe(fds)){
		perror("pipe");
		exit(1);
	}
	pid_t pid;
	pid = fork();
	if(pid == 0){
		//child recive
		close(fds[1]);
		char buf[1024]="";

		read(fds[0],buf,1023);
		
		printf("child:%s\n",buf);
		close(fds[0]);
	}
	else
	{
		//parent send
		//char* p = "hello world";
		char p[1024]="";
		scanf("%s",p);
		write(fds[1],p,strlen(p));
		char buf1[1024]="";
		read(fds[0],buf1,1023);
		printf("parent:%s\n",buf1);
	//	sleep(1);
	//	wait(NULL);

		close(fds[1]);
		close(fds[0]);
	}
	
	return 0;
}
