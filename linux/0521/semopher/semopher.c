#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
 #include <sys/sem.h>
#include<sys/wait.h>
int main(int argc, char* argv[])
{
	int semid=semget(IPC_PRIVATE,1,IPC_CREAT|0600);
	printf("the semid value is %d\n",semid);
	struct sembuf sem0;
	sem0.sem_num=0;
	sem0.sem_op=1;
	sem0.sem_flg=SEM_UNDO;
	
	if(!fork())
	{
		//child
		/*
		int ret;
		ret = semctl(semid,0,IPC_RMID);	
		if(ret != 0)
		{
			perror("semctl");
			exit(1);
		}
		*/
		printf("bye");

	}
	else
	{
		//parent
		sleep(3);
		wait(NULL);
		int ret;
		ret=semop(semid,&sem0,sizeof(struct sembuf));
		if(ret!=0)
			perror("semop");
		return 0;
	
	}


}
