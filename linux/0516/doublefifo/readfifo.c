#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
//readfirst  2
int main(int argc, char* argv[])
{
	int fdr=open(argv[1],O_RDONLY);//1-2
	int fdw=open(argv[2],O_WRONLY);//2-1
	char buf[100];
	if(fdr==-1|fdw==-1){
		perror("open");
		exit(1);
	}
	while(memset(buf,0,sizeof(buf)),read(fdr,buf,50)!=0)
	{
		fputs(buf,stdout);
		memset(buf,0,sizeof(buf));
		read(STDIN_FILENO,buf,50);
		write(fdw,buf,strlen(buf)+1);
	}
	
	return 0;
}
