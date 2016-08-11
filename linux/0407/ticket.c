#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>


typedef struct tag
{
	int i_g;
	pthread_mutex_t mylock;
}NODE,*pNODE;

void* handle(void* arg)
{
	pNODE p = (pNODE)arg;

	while(1){
		pthread_mutex_lock(&p->mylock);

		if(p->i_g<=0){
			pthread_mutex_unlock(&p->mylock);
			continue;
		}

		printf("%u sell a ticket:%d\n",(unsigned int)pthread_self(),p->i_g);
		p->i_g = p->i_g-1;
		pthread_mutex_unlock(&p->mylock);
		sleep(3);
	}	
}

int main(int argc, char* argv[])
{
	pthread_t thd1,thd2,thd3;
	//pthread_mutex_t lock;
	NODE anode;
	memset(&anode,0,sizeof(anode));
	anode.i_g=500;
	pthread_mutex_init(&anode.mylock,NULL);


	while(anode.i_g>0){
		if(pthread_create(&thd1,NULL,handle,(void*)&anode)!=0)
		{
			printf("pthread error\n");
			exit(-1);
		}

		if(0!=pthread_create(&thd2,NULL,handle,(void*)&anode))
		{
			printf("pthread error\n");
			exit(-1);
		}


		if(0!=pthread_create(&thd3,NULL,handle,(void*)&anode))
		{
			printf("pthread error\n");
			exit(-1);
		}
		if(anode.i_g < 0){	
			printf("i_g:%d\n",anode.i_g);
			break;
		}
	}
	while(1);
	
	pthread_join(thd1,NULL);
	pthread_join(thd2,NULL);
	pthread_join(thd3,NULL);

	pthread_mutex_destroy(&anode.mylock);
	printf("cnt:\n");

	return 0;

}
