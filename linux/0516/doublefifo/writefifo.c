#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
//write
int main(int argc, char* argv[])
{
	int fdw=open(argv[1],O_WRONLY);//1-2
	int fdr=open(argv[2],O_RDONLY);//2-1
	char buf[100];
	if(fdw ==-1||fdr ==-1){
		perror("open");
		exit(1);
	}
	printf("open sucess:fdr:%d,fdw:%d",fdr,fdw);
	while(memset(buf,0,sizeof(buf)),read(STDIN_FILENO,buf,50)!=0){

		write(fdw,buf,strlen(buf)+1);
		memset(buf,0,sizeof(buf));
		read(fdr,buf,50);
		fputs(buf,stdout);
	}
	return 0;
}

