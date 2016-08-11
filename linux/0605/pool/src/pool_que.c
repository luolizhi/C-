#include"pool_que.h"
/*
typedef enum
{
	EMPTY,FULL,OTHER
}STATUS;
typedef struct que
{
	elem_t* que_arr;
	int que_front;
	int que_tail;
	int que_capacity;
	pthread_mutex_t que_lock;
	pthread_cond_t que_pro;
	pthread_cond_t que_con;	//que empty
}que_t,*pque_t;
*/
void que_init(pque_t pq,int sizenum)
{
	pq->que_arr = (elem_t*)calloc(sizenum,sizeof(elem_t));
	pq->que_capacity = sizenum;

	pq->que_tail = 0;
	pq->que_front =0;
	
	pthread_mutex_init(&pq->que_lock,NULL);
	
	pthread_cond_init(&pq->que_pro,NULL);
	pthread_cond_init(&pq->que_con,NULL);
}

STATUS que_empty(pque_t pq)
{
	if(pq->que_tail == pq->que_front)
	{
		return EMPTY;
	}else
		return OTHER;
}
STATUS que_full(pque_t pq)
{
	if((pq->que_tail+1)%pq->que_capacity == pq->que_front)
	{
		return FULL;
	}
	else
		return OTHER;
}

void que_push(pque_t pq,elem_t val)
{
	pthread_mutex_lock(&pq->que_lock);
	while(que_full(pq)==FULL)
	{
		pthread_cond_wait(&pq->que_pro,&pq->que_lock);
	}
	pq->que_arr[pq->que_tail] = val;
	pq->que_tail = (pq->que_tail+1)%pq->que_capacity;

	pthread_cond_signal(&pq->que_con);
	pthread_mutex_unlock(&pq->que_lock);

}

elem_t que_top(pque_t pq)
{
	pthread_mutex_lock(&pq->que_lock);
	while(que_empty(pq)==EMPTY)
	{
		pthread_cond_wait(&pq->que_con,&pq->que_lock);
	}
	return pq->que_arr[pq->que_front];
}

void que_pop(pque_t pq)
{
	pq->que_front = (pq->que_front+1)%pq->que_capacity;
	pthread_cond_signal(&pq->que_pro);
	pthread_mutex_unlock(&pq->que_lock);
}


void que_destroy(pque_t pq)
{
	free(pq->que_arr);
	pthread_mutex_destroy(&pq->que_lock);
	pthread_cond_destroy(&pq->que_pro);
	pthread_cond_destroy(&pq->que_con);
}
