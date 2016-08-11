#include "pool_pthread.h"

void pool_init(pthreadspool_t ppool,int quecapcity,int threadsnum,consumer_handle hd)
{
	que_init(&ppool->pool_que,quecapcity);
	ppool->pool_cnt = threadsnum;
	ppool->pool_arr = (pthread_t*)calloc(threadsnum,sizeof(pthread_t));
	ppool->pool_handle = hd;
}

void pool_on(pthreadspool_t ppool)
{
	int index;
	for(index=0;index<ppool->pool_cnt;index++)
	{
		if(pthread_create(ppool->pool_arr+index,NULL,ppool->pool_handle,NULL)!=0){
		printf("pthread_create fail!\n");
		exit(1);
		}
	}

}



void pool_off(pthreadspool_t ppool)
{
	int index;
	for(index=0;index<ppool->pool_cnt;index++)
	{
		if(pthread_join(ppool->pool_arr[index],NULL)!=0){
		printf("pthread_join fail!\n");
		exit(1);
		}
	}

}

void pool_put(pthreadspool_t ppool, elem_t val)	//put into pool
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



