#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/time.h>

void handle(int sig)
{
	time_t tt;
	time(&tt);
	struct tm *nowt;
	nowt = gmtime(&tt);
	printf("hour:%d,min:%d,sec:%d\n",(8+nowt->tm_hour),nowt->tm_min,nowt->tm_sec);
}


int main(int argc, char* argv[])
{
	signal(SIGALRM,handle);
	signal(SIGVTALRM,handle);
	//	alarm(1);
	kill(0,14);
	kill(0,SIGVTALRM);
	struct itimerval tmer;
	tmer.it_value.tv_sec=1;
	tmer.it_value.tv_usec=1;
	tmer.it_interval.tv_sec=2;
	tmer.it_interval.tv_usec=0;
	
	if(setitimer(ITIMER_REAL,&tmer,NULL)==-1){
		perror("setitimer");
		exit(1);
	}

	sleep(5);
	while(1);
	




	return 0;
}
