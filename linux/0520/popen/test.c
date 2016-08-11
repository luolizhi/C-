#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define PERM S_IRUSR|S_IWUSR	//0600

int main(int argc, char* argv[])
{	
	int shmid = shmget(IPC_PRIVATE,1024,PERM);
	if(shmid==-1)
	{
		fprintf(stderr,"creat share memory error:%s\n\a",strerror(errno));
		exit(1);
	}
	if(fork()>0)	//parent
	{
		char* p_addr=(char*)shmat(shmid,NULL,0);
		memset(p_addr,'\0',1024);
		strncpy(p_addr,"share memory",1024);
		printf("parent%d write buffer:%s\n",getpid(),p_addr);
		sleep(2);
		wait(NULL);
		shmctl(shmid,IPC_RMID,0);
		exit(0);
	}
	else
	{	//child
		sleep(5);
		char* c_addr=(char*)shmat(shmid,NULL,0);
		printf("client pid=%d,shmid=%d,read buffer:%s\n",getpid(),shmid,c_addr);
		exit(0);
	
	}
	return 0;
}

void example1()
{
	FILE* fp=popen("cat /etc/profile","r");
	char  buf[512]={0};
	puts(buf);
	while(fgets(buf,sizeof(buf),fp))
	{
		puts(buf);
	}
	pclose(fp);
}

void example2()
{
	char buf[]={"aaa bb ccc ddd ee   ffff ggg  hhh"};
	FILE* fp=popen("wc -w","w");
	fwrite(buf,sizeof(buf),1,fp);
	pclose(fp);
}

void example3()
{
	int fds[2];
	pipe(fds);
	char szbuf[10]={0};
	if(fork()==0)
	{
		//child
		close(fds[1]);	//close write
		sleep(2);
		if(read(fds[0],szbuf,sizeof(szbuf))>0)
			puts(szbuf);
		close(fds[0]);	//close read
	}
	else
	{
		close(fds[0]);
		write(fds[1],"hello",6);
		wait(NULL);
		write(fds[1],"world",6);
		close(fds[1]);
	}
}
