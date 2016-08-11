#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sighandle(int sig)
{
	printf("the sig is %d\n",sig);
	
}
int main()
{
	signal(SIGALRM,sighandle);
	alarm(3);
//	sleep(5);
	printf("befor pause().\n");
	pause();
	printf("after pause()\n");

	return 0;
}
