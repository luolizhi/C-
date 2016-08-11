#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
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
	int shmid = shmget((key_t)1234,sizeof(mem_t),0);
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
	
	pm ->m_lock = 1;
	pm ->m_unshow =0;


	while(1){
		Lock(pm);
		while(pm->m_unshow==0){
			unLock(pm);
			sleep(1);
			Lock(pm);
		}
		printf("mem:%s",pm->m_buf);
		pm->m_unshow = 0;
		unLock(pm);
	}
	shmdt(pm);
	return 0;
}
