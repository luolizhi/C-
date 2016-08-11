#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int g_iseq=0;
void handle(int signo)
{
	printf("\nsigno:%d\n",signo);
}
//void     (*sa_sigaction)(int, siginfo_t *, void *);

void SignHandlerNew(int iSignno,siginfo_t * pInfo,void* pReserved)
{
	int iseq = g_iseq++;
	printf("\n%d Enter signalhandlernew, signo:%d\n",iseq,iSignno);
	sleep(3);
	printf("\nthe send process pid:%d\n",pInfo->si_pid);
	printf("\nthe send process uid:%d\n",pInfo->si_uid);
	printf("\n%d leave signalhandlernew, signo:%d\n",iseq,iSignno);

}


int main(int argc,char* argv[])
{
	char szBuf[8]={0};
	int iRet = 0;



	printf("pid:%d\n",getpid());
	struct sigaction st;
	st.sa_sigaction = SignHandlerNew;
	st.sa_flags = SA_SIGINFO|SA_RESTART;
	sigemptyset(&st.sa_mask);
	sigaddset(&st.sa_mask,SIGQUIT);

	sigaction(SIGINT,&st,NULL);
	sigaction(SIGQUIT,&st,NULL);
	
	do{
		iRet=read(STDIN_FILENO,szBuf,sizeof(szBuf)-1);
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


void test1()
{
	printf("pid:%d\n",getpid());
	struct sigaction st;
	st.sa_handler = handle;
	st.sa_flags = 0;
	sigaction(SIGINT,&st,NULL);
	sigaction(SIGQUIT,&st,NULL);
}
