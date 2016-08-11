#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int fd=open(argv[1],O_WRONLY);
	char buf[100];
	while(memset(buf,0,sizeof(buf)),read(STDIN_FILENO,buf,50)!=0){

		write(fd,buf,strlen(buf)+1);
	
	}

	return 0;
}
