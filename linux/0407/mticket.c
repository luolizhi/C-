#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

pthread_cond_t cond1,cond2;	//cond1 seller 

typedef struct tag
{
	int ticketcount;
	pthread_mutex_t lock;
}NODE,*pNODE;


void* sale1(void* args)
{
	pNODE p = (pNODE)args;
	
	while(1){
		pthread_mutex_lock(&p->lock);
		if(p->ticketcount > 0){

		printf("sale1 sell the ticket is:%d\n",p->ticketcount);
			sleep(2);	
			p->ticketcount--;
			pthread_mutex_unlock(&p->lock);
			printf("sale1 finished.\n");
			pthread_exit(NULL);
		}else
		{

			pthread_mutex_unlock(&p->lock);

			pthread_cond_signal(&cond2);
			
			pthread_cond_wait(&cond1,&p->lock);
		//	sleep(3);
		//	pthread_exit(NULL);
		}
	}
}

void* sale2(void* args)
{
	pNODE p = (pNODE)args;
	while(1){
		pthread_mutex_lock(&p->lock);
		if(p->ticketcount>0){

			printf("sale 2 sell the ticket is:%d\n",p->ticketcount);
			sleep(2);	
			p->ticketcount--;
			pthread_mutex_unlock(&p->lock);
			printf("sale 2 finished.\n");
		}
		else
		{

			pthread_mutex_unlock(&p->lock);
			pthread_cond_signal(&cond1);
			
			pthread_cond_wait(&cond2,&p->lock);
			//pthread_exit(NULL);
		}
		sleep(1);
	}
}



int main(int argc,char* argv[])//m seller
{
	pthread_t thd1 =0;
	pthread_t thd2 =0;

	NODE anode;
	memset(&anode,0,sizeof(anode));
	if(pthread_mutex_init(&anode.lock, NULL)!=0)
	{
		printf("mutex_init fail!\n");
		exit(1);
	}
	anode.ticketcount = 10;
	
	if(pthread_cond_init(&cond1,NULL))
	{
		printf("cond_init fail!\n");
		exit(1);
	}
	
	if(pthread_cond_init(&cond2,NULL))
	{
		printf("cond_init fail!\n");
		exit(1);
	}
	pthread_create(&thd1,NULL,sale1,(void*)&anode);
	pthread_create(&thd2,NULL,sale2,(void*)&anode);

	while(1){
		//wait
		pthread_mutex_lock(&anode.lock);
		if(anode.ticketcount > 0)
		{
			pthread_cond_wait(&cond2,&anode.lock);

		}
		anode.ticketcount += 5;
		printf("ticket on!\n");
		
		pthread_cond_signal(&cond1);

		pthread_mutex_unlock(&anode.lock);
		
	}




	printf("ticketcount : %d\n",anode.ticketcount);

	pthread_join(thd1,NULL);
	pthread_join(thd2,NULL);

	pthread_cond_destroy(&cond1);
	pthread_cond_destroy(&cond2);
	return 0;
}
