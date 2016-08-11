#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sig_handl(int id)
{
	printf("\nthe id is %d!\n",id);
}


int main(int argc, char* argv[])
{
	
	signal(SIGINT,sig_handl);
	while(1);
	return 0;
}
