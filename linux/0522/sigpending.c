#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int signum,siginfo_t* pInfo,void* pReversed)
{
	printf("receive signal %d\n",signum);
}

int main(int argc,char* argv[])
{
	sigset_t new_mask, old_mask, pending_mask;
	sigemptyset(&new_mask);
	sigaddset(&new_mask,SIGINT);
	if(sigprocmask(SIG_BLOCK,&new_mask,&old_mask))
		printf("block signal SIGINT error\n");

	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	if(sigaction(SIGINT,&act,NULL))	//success return 0;
		printf("install signal SIGINT error\n");
	
	if(sigismember(&pending_mask,SIGINT))	//in member return 1
		printf("signal SIGINT is pending\n");

	if(sigprocmask(SIG_SETMASK,&old_mask,NULL)<0)	//success return 0;
		printf("unblock signal error\n");
	
	printf("signal unblocked\n");
	sleep(10);
	return 0;
}







