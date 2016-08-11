#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<time.h>

int main(int argc, char* argv[])
{
	int shmid=shmget((key_t)56,1024,IPC_CREAT | 0600);
	struct shmid_ds shm_stru;
	int ret;
	ret = shmctl(shmid,IPC_STAT,&shm_stru);
	printf("the uid is %d\n",shm_stru.shm_perm.__key);

	return 0;
}
