#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

typedef struct tag {
	int ticketcount;
	pthread_mutex_t lock;
	pthread_cond_t cond1,cond2;	//cond1 seller 
}NODE,*pNODE;


void* sale(void* arg)
{
	pNODE p = (pNODE)arg;

	while(1){
		pthread_mutex_lock(&p->lock);
		while(p->ticketcount <= 0)	//not if
		{
			pthread_cond_signal(&p->cond2);

			pthread_cond_wait(&p->cond1,&p->lock);
		}
		printf("%d sell %d\n",getpid(),p->ticketcount);
		p->ticketcount--;
		pthread_mutex_unlock(&p->lock);		
	}
}

void* putter(void* arg)
{
	pNODE p = (pNODE)arg;
	while(1){
		pthread_mutex_lock(&p->lock);
		while(p->ticketcount > 0){
			pthread_cond_wait(&p->cond2,&p->lock);
			pthread_cond_signal(&p->cond1);
		}
		p->ticketcount += 10;
		printf("tickets on\n");
		sleep(1);
		pthread_mutex_unlock(&p->lock);
	}

}


int main(int argc,char* argv[])//m seller ,n putter
{
	if(argc!=3)
	{
		printf("wrong argv!\n");
		exit(1);
	}
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	pthread_t arr[m+n];
	memset(arr,0,sizeof(arr));
	NODE anode;
	memset(&anode,0,sizeof(anode));
	if(pthread_mutex_init(&anode.lock, NULL)!=0)
	{
		printf("mutex_init fail!\n");
		exit(1);
	}
	anode.ticketcount = 0;
	
	if(pthread_cond_init(&anode.cond1,NULL))
	{
		printf("cond_init fail!\n");
		exit(1);
	}
	
	if(pthread_cond_init(&anode.cond2,NULL))
	{
		printf("cond_init fail!\n");
		exit(1);
	}

	int index = 0;
	
	while(m){
		if(pthread_create(&arr[index],NULL,sale,(void*)&anode)!=0)
		{
			printf("pthread_create sale fail!\n");
			exit(1);
		}
			m--;
		index++;
	}
	while(n){
		if(pthread_create(&arr[index],NULL,putter,(void*)&anode)!=0){
		printf("pthread_create putter fail\n");
		exit(1);
		}
		n--;
		index++;
	}

	index--;

	while(index)
	{
		pthread_join(arr[index],NULL);
		index--;
	}



	pthread_cond_destroy(&anode.cond1);
	pthread_cond_destroy(&anode.cond2);
	return 0;
}
