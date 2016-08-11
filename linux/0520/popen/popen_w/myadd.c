#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main(int argc,char* argv[])
{
	int left,right;
	scanf("%d%d",&left,&right);
	printf("pid:%d\n",getpid());
	printf("%d + %d = %d\n",left,right,left+right);
	return 0;

}
