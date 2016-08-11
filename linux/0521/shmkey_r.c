#include<stdio.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<sys/types.h>
#include<errno.h>

typedef struct showlock
{
	int val;
	int unshow;
	int lock;	//0 lock  1  unlock
}showl, *pshowl;

void lock(int* lock)
{
	while(1)
	{
		if(*lock==1)
		{
			*lock=0;
			break;
		}
	}

}

void unlock(int *lock)
{
	*lock=1;
}



int main(int argc, char* argv[])
{
	key_t shmkey=ftok(argv[1],1);
	int shmid=shmget(shmkey,1024,IPC_CREAT|0600);
	if(shmid==-1)
	{
		perror("shmget");
		exit(1);
	}
	pshowl shm_addr=(pshowl)shmat(shmid,NULL,0);
	shm_addr->lock=1;
	printf("the lock value is %d\n",shm_addr->lock);
	printf("custom\n");
	while(1){
		lock(&shm_addr->lock);
		printf("the val value is %d\n",shm_addr->val);
		shm_addr->val=0;
		shm_addr->unshow=1;
		printf("i have spend val value is %d\n",shm_addr->val);
		unlock(&shm_addr->lock);
		sleep(1);
	}
	int ret;
	ret=shmdt(shm_addr);	//close
	if(ret!=0){
		perror("shmdt");
		exit(1);
	}
	sleep(15);
	ret=shmctl(shmid,IPC_RMID,NULL);
	if(ret!=0)
	{
		perror("shmctl");
		exit(1);
	}
	return 0;
}






