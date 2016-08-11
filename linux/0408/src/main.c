#include "pool_pthread.h"


void* handle(void* arg)
{
	//pool_get
	//excute task
	printf("hello world:%u\n",(unsigned int)pthread_self());
}


int main(int argc, char* argv[])	//capacity  num
{
	if(argc != 3)
	{
		printf("wrong argc(EXE CAPCITY THREADNUM)\n");
		exit(1);
	}
	
	threadspool_t mypool;
	//memset(&mypool,0,sizeof(mypool));
	pool_init(&mypool,atoi(argv[1]),atoi(argv[2]),handle);

	pool_on(&mypool);
	
	char buf[128];

	while(1){
		fd_set rds;
		FD_ZERO(&rds);
		FD_SET(0,&rds);

		struct timeval tm;
		tm.tv_sec = 1;
		tm.tv_usec = 0;
		if(select(1024,&rds,NULL,NULL,&tm)==0)
		{
			continue;	//the code below won't execute
		}
		if(FD_ISSET(0,&rds))
		{
			memset(buf,0,sizeof(buf));
			if(read(0,buf,sizeof(buf)-1)==0)
			{
				break;
			}
			//init a task;
			elem_t val ;
			sscanf(buf,"%d%d",&val.left,&val.right);
			pool_put(&mypool,val);
		}
	}

	pool_off(&mypool);
	pool_destroy(&mypool);
	return 0;
}
