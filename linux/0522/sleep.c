#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void signhandler(int isignNo)
{
	printf("signal:%d",isignNo);
}

int main(int argc, char* argv[])
{
	signal(SIGALRM,signhandler);

	alarm(3);
	printf("befor pause().\n");
	pause();
	printf("after pause().\n");

	return 0;
}
