#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>


int main(int argc, char* argv[])
{
	FILE* fp = fdopen(1,"w");
	char* p ="hello world!\n";
	fprintf(fp, "%s\n",p);

	return 0;
}
/*
void test1()
{

	int fd1 = open(argv[1],O_RDONLY);
	int fd2;
	int readn;

	fd2=fd1;
	close(fd1);
	char buf[1024]="";
	readn = read(fd2,buf,sizeof(buf));
	if(readn==-1)
			perror("read");
	printf("readn:%d,%s\n",readn,buf);
}

void test2
{
	int fd1 = open(argv[1],O_RDONLY);
	int fd2;
	int readn;
	fd2 = dup(fd1);
	//fd2=fd1;
	close(fd1);
	char buf[1024]="";
	readn = read(fd2,buf,sizeof(buf));
	if(readn==-1)
			perror("read");
	printf("readn:%d,%s\n",readn,buf);
	close(fd2);
}

void test3
{
	int fd = fileno(stdin);
	char buf[1024]="";
	printf("strlen:%d\n",strlen(buf));
	read(0,buf,strlen(buf));

	write(1,buf,strlen(buf));

	return 0;

}


 
 
 */
