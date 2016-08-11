#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc,char* argv[])
{
	
	int fds0[2];	//parent -> child
	int fds1[2];	//child -> parent
	//fds[0] read; fds[1] write
	if(pipe(fds0)==-1||pipe(fds1)==-1)
		{
			perror("pipe");
			exit(1);
		}
			pid_t pid;
			pid = fork();
	if(pid > 0){
			//parent 
	int left,right;
			close(fds0[0]);
			close(fds1[1]);
	while(scanf("%d%d",&left,&right)!=EOF){
			char buf[128];
			memset(buf,0,sizeof(buf));
			//write into fds0[1]
			sprintf(buf,"%d %d\n",left, right);
			write(fds0[1],buf,strlen(buf));
			
			//read from fds1[0]
			memset(buf,0,sizeof(buf));
			read(fds1[0],buf,strlen(buf));
			printf("%s\n",buf);
	}

			}
	else if(pid == 0){
		//child
		close(fds0[1]);
		close(fds1[0]);
		
		dup2(fds0[0],0);
		dup2(fds1[1],1);

		if(execl("./myadd","./myadd",NULL)==-1)
		{
			perror("execl");
			exit(1);
		}
	
	}
			return 0;
}






