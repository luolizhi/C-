#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>

void SingnHandle(int iSingnNo)
{
	printf("capture signal no:%d\n",iSingnNo);
}

int main(int argc,char* argv[])
{
//	signal(SIGINT,SingnHandle);
	signal(SIGINT,SIG_IGN);
//	signal(SIGINT,SIG_DFL);
	while(1)
		sleep(1);
	return 0;
}
