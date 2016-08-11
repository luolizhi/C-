#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
typedef struct tag
{
	int i_gval ;
	pthread_mutex_t lock;
}NODE,*pNODE;
void* thd_handle(void* arg)
{
	int cnt = 100000000;
	pthread_mutex_t* plock = (pthread_mutex_t*)arg;

	while(cnt){
		pthread_mutex_lock(plock);
	
		i_gval++;

		pthread_mutex_unlock(plock);
		cnt--;
	}
	pthread_exit(NULL);
}


int main(int argc, char* argv[])
{
	pthread_t thd1,thd2;
	
	pthread_mutex_t mylock;
   if(pthread_mutex_init(&mylock,NULL)!=0){
   		printf("pthread_mutex_init failed!\n");
		exit(-1);
   }

	if(pthread_create(&thd1,NULL,thd_handle,(void*)&mylock)!=0)
	{
		printf("pthread_create failed!\n");
		exit(-1);
	}

	if(pthread_create(&thd2,NULL,thd_handle,(void*)&mylock)!=0)
	{
		printf("pthread_create failed!\n");
		exit(-1);
	}
	
	pthread_join(thd1,NULL);
	pthread_join(thd2,NULL);

	printf("i_gval:%d\n",i_gval);
	return 0;
}
