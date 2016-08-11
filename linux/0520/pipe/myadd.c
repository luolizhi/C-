#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int left, right;
	char line[128];
	while(memset(line,0,sizeof(line)),read(0,line,sizeof(line))!=0){
		sscanf(line,"%d%d",&left,&right);
		memset(line,0,sizeof(line));
		sprintf(line,"add pid:%d,%d + %d=%d\n",getpid(),left,right,left+right);
		write(1,line,strlen(line));
	}
	return 0;
}
