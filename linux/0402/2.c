#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

union semun {
	int val;/*value for SETVAL*/
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};


int main(int argc, char* argv[])
{
	//sem
	int semid = semget((key_t)1234,1,0);
	union semun mysem;
	memset(&mysem,0,sizeof(mysem));
	mysem.val=1;
	semctl(semid,0,IPC_SET,mysem);
	struct sembuf myop;
	memset(&myop,0,sizeof(myop));
	int cnt =atoi(argv[1]);
	
	//shm
	int shmid = shmget((key_t)1024,4,0);
	if(shmid == -1)
	{
		perror("shmid");
		exit(1);
	}
	int* p = (int *)shmat(shmid,NULL,0);

	while(cnt>0)
	{
		cnt--;
		memset(&myop,0,sizeof(myop));
		myop.sem_num=0;
		myop.sem_op =-1;
		myop.sem_flg = SEM_UNDO;//p
		semop(semid,&myop,1);
		
		
		(*p)++;
		
		memset(&myop,0,sizeof(myop));
		myop.sem_num=0;
		myop.sem_op =1;
		myop.sem_flg = SEM_UNDO;//v
		semop(semid,&myop,1);
	}
	printf("over\n");

	while(1);



	return 0;
}
