#include<stdio.h>
#include<pthread.h>

void* handle(void* arg)
{
	pthread_mutex_t mylock = (pthread_mutex_t)arg;
	pthread_mutex_lock(mylock);
	//pthread_mutex_lock(&mylock);
	printf("hello\n");
	sleep(1);
	pthread_exit(NULL);
}


int main()
{
	pthread_t thd;
	pthread_mutex_t lock;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&thd,NULL,handle,(void*)&lock);
	pthread_join(thd,NULL);
	
	pthread_mutex_destroy(&lock);


	return 0;
}
