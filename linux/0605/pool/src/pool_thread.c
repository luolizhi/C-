#include"pool_pthread.h"
/*
typedef void* (*consumer_handle)(void*);
typedef struct threads
{
	que_t pool_que;
	int pool_cnt;
	pthread_t* pool_arr;
	consumer_handle pool_handle;
}threadspool_t,*pthreadspool_t;
*/

void pool_init(pthreadspool_t ppool,int quecapacity, int threadnum,consumer_handle hd)
{
	que_init(&ppool->pool_que,quecapacity);
	ppool->pool_arr = (pthread_t*)calloc(threadnum,sizeof(pthread_t));
	ppool->pool_handle = hd;
	ppool->pool_cnt = threadnum;
}
void pool_on(pthreadspool_t ppool)
{
	int index;
	for(index=0;index<ppool->pool_cnt;index++)
	{
		//if(0==pthread_create(ppool->pool_arr+index,NULL,ppool->pool_handle,NULL))
		{
			perror("pthread_create");
			exit(1);
		}
	}

}
void pool_off(pthreadspool_t ppool)
{
	int index;
	for(index=0;index<ppool->pool_cnt;index++)
	{
		pthread_join(ppool->pool_arr[index],NULL);
	}
	
}

void pool_put(pthreadspool_t ppool,elem_t val)
{
	que_push(&ppool->pool_que,val);
}

void pool_get(pthreadspool_t ppool,elem_t* val)
{
	*val = que_top(&ppool->pool_que);
	que_pop(&ppool->pool_que);
}
void pool_destroy(pthreadspool_t ppool)
{
	que_destroy(&ppool->pool_que);
	free(ppool->pool_arr);
}
