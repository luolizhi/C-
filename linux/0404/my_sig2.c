#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
typedef void (*pfunc_t)(int) ;
void sig_handle(int signum)
{
	printf("\nrecive a signal:%d\n",signum);
}
void sig_handle2(int signum, siginfo_t * pinfo, void* pvoid)
{
	printf("\nrecive a signal:%d\n",signum);
}

void sethandle(int signum,pfunc_t pf)
{
}


int main(int argc, char* argv[])
{
	struct sigaction myact;
	memset(&myact,0,sizeof(myact));
	myact.sa_sigaction  = sig_handle2;
	sigemptyset(&myact.sa_mask);
	myact.sa_flags = SA_RESTART|SA_SIGINFO;

	sigaction(SIGINT,&myact,NULL);

	char buf[1024];
	memset(buf,0,sizeof(buf));
	int readn = read(0,buf,sizeof(buf)-1);
	printf("readn:%d\n",readn);
	if(readn==-1){
		perror("read");
		exit(1);
	}
	return 0;
}
