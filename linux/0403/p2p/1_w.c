#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<time.h>
#include<sys/select.h>

typedef struct my_mem
{
	int m_lock;
	int m_unshow;
	char m_buf[128];
}mem_t,*pmem_t;

void Lock(pmem_t pm)
{
	while(pm->m_lock==0){
		sleep(1);
	}
	//get lock
	pm->m_lock = 0;
}

void unLock(pmem_t pm)
{
	pm->m_lock = 1;
}

int main(int argc, char* argv[])
{
	char line[128];
	int fd_r,fd_w;

	//fifo
	fd_w = open("./12fifo",O_WRONLY);
	fd_r = open("./21fifo",O_RDONLY);
	printf("fd_w:%d,fd_r:%d\n",fd_w,fd_r);




	//shm
	int shmid = shmget((key_t)1234,sizeof(mem_t),IPC_CREAT|0666);
	if(shmid == -1)
	{
		perror("shm");
		exit(1);
	}
	pmem_t pm = (pmem_t)shmat(shmid,NULL,0);
	if((void *)pm==(void *)-1)
	{
		perror("shmat");
		exit(1);
	}

	pm->m_lock = 1;
	pm ->m_unshow =0;


	//select
	fd_set rds;
	struct timeval tm;
	int ret;


	while(1){
		FD_ZERO(&rds);
		FD_SET(0,&rds);
		FD_SET(fd_r,&rds);

		tm.tv_usec=0;
		tm.tv_sec=5;
		ret = select(1024,&rds,NULL,NULL,&tm);

		if(ret == 0){
			continue;
		}
		else if(ret > 0)
		{
			if(FD_ISSET(0,&rds)){
				//input from keyboard
				memset(line,0,sizeof(line));
				read(0,line,sizeof(line)-1);
				write(fd_w,line,strlen(line));
			}
			if(FD_ISSET(fd_r,&rds)){
				//from 21fifo
				memset(line,0,sizeof(line));
				read(fd_r,line,sizeof(line)-1);
				Lock(pm);
				while(pm->m_unshow==1){
					unLock(pm);
					sleep(1);
					Lock(pm);
				}
				strcpy(pm->m_buf,line);

				pm->m_unshow = 1;
				unLock(pm);


			}
		}
	}
	shmdt(pm);
	close(fd_r);
	close(fd_w);
	return 0;
}
