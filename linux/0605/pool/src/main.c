#include"pool_pthread.h"

void* handle(void* num)
{
	//pool_get
	//excue task
	printf("hello world:%u\n",(unsigned int)pthread_self());
}

int mian(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("EXE CAPACITY THREADS_NUM\n");
		exit(1);
	}

	threadspool_t mypool;

	pool_init(&mypool,atoi(argv[1]),atoi(argv[2]),handle);
	pool_on(&mypool);
	
	char buf[128];
	while(1)
	{
		fd_set rds;
		FD_ZERO(&rds);
		FD_SET(0,&rds);

		struct timeval tm;
		tm.tv_sec = 1;
		tm.tv_usec = 0;

		if(0==select(1024,&rds,NULL,NULL,&tm))
		{
			continue;
		}
		if(FD_ISSET(0,&rds))
		{
			memset(buf,0,sizeof(buf));
			if(read(0,buf,127)==0)
			{
				break;
			}
			//init a task
			elem_t val =1024;
			pool_put(&mypool,val);
		}
			
	}
	pool_off(&mypool);
	pool_destroy(&mypool);






	return 0;
}
