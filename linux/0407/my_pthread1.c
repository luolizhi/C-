#include<stdio.h>
#include<pthread.h>

void* handle(void *arg)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("child:%d\n",(int)arg);
		sleep(1);
	}
	pthread_exit(NULL);

}


int main(int argc, char* argv[])
{
	pthread_t thd;
	pthread_create(&thd,NULL,handle,(void*)123);
	int i;
	for(i=0;i<10;i++)
	{
		printf("parent:%x\n",(unsigned int)thd);
		sleep(1);
	}
	pthread_join(thd,NULL);
	return 0;
}
