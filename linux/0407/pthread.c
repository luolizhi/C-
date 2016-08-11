#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* thd_handle(void* arg)
{
	printf("thd:%u\n",(unsigned int)pthread_self());
	printf("thread:%s\n",(char*)arg);
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t thd1,thd2,thd3;
	char *p = "hello world!\n";
	printf("main:%u\n",(unsigned int)pthread_self());
	if(pthread_create(&thd1,NULL,thd_handle,(void*)p)==-1)
	{
		perror("pthread_create");
		exit;
	}
	if(pthread_create(&thd2,NULL,thd_handle,(void*)p)==-1)
	{
		perror("pthread_create");
		exit;
	}
	if(pthread_create(&thd3,NULL,thd_handle,(void*)p)==-1)
	{
		perror("pthread_create");
		exit;
	}
	pthread_join(thd1,NULL);	
	pthread_join(thd2,NULL);	
	pthread_join(thd3,NULL);	
	while(1);
	return 0;
}


