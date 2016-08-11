#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int g_iSeq = 0;

void SignHandle(int iSignNo)
{
	int iSeq = g_iSeq++;
	printf("%d enter signalhandle,signo:%d\n",iSeq,iSignNo);
	sleep(3);
	printf("%d leave signalhandle,signo:%d\n",iSeq,iSignNo);
}

int main(int argc, char* argv[])
{
	char szBuf[8];
	int iRet;
	signal(SIGINT,SignHandle);
	signal(SIGQUIT,SignHandle);
	do{
		iRet = read(STDIN_FILENO,szBuf,sizeof(szBuf)-1);
		if(iRet < 0)
		{
			perror("read");
			exit(1);
		}
		szBuf[iRet]=0;
		printf("get:%s",szBuf);
	}while(strcmp(szBuf,"quit\n")!=0);
	return 0;
	
}
