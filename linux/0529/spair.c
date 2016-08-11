#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>

int socketpair(int domain, int type, int protocol, int sv[2]);

int main(int argc, char* argv[])
{
	int fd[2];
	int r = socketpair(AF_LOCAL,SOCK_STREAM,0,fd);
	if(r < 0)
	{
		perror("socketpair()");
		exit(1);
	}

	if(fock())	//parent process: echo client
	{
		int val = 0;
		close(fd[1]);	//write close
		while(1)
		{
			sleep(1);
			++val;
			printf("sending data:%d\n",val);
			write(fd[0],&val,sizeof(val));
			read(fd[0],&val,sizeof(val));
			printf("data received:%d\n",val);
		}
	}
	else		//child process:echo server
	{
		int val;
		close(fd[0]);
		while(1){
			read(fd[1],&val,sizeof(val));
			++val;
			write(fd[1],&val,sizeof(val));
		}
	}


}









