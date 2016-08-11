#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

sig_atomic_t child _exit_status;

void clean_up_child_process(int signal_num)
{
	/*clean uo child process*/
	int status;
	wait(&status);
	/*store its exit status in a global variable*/
	child_exit_status = status;
}





int main(int argc, char* argv[])
{
	//fork a child process
	pid_t pid;
	pid = fork();
	//error
	if(pid < 0)
	{
		perror("fork");
		exit(1);
	}
	
	//child
	else if( pid == 0)
	{
		cnt++;
		printf("cnt:%d\n",cnt);
		printf("in child process, and exit!\n");
		printf("pid:%d,ppid:%d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("in parent process,sleep for one miniute ...zZ...\n");
		printf("pid:%d,ppid:%d\n",getpid(),getppid());
	//	sleep(0.0001);
		printf("after sleeping, and exit!\n");
	}
	return 0;


}


void test1()
{
	while(1){
		//fork a child process
	pid_t pid;
	pid = fork();
	//error
	if(pid < 0)
	{
		perror("fork");
		exit(1);
	}
	
	//child
	else if( pid == 0)
	{
		cnt++;
		printf("cnt:%d\n",cnt);
		printf("in child process, and exit!\n");
		printf("pid:%d,ppid:%d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("in parent process,sleep for one miniute ...zZ...\n");
		printf("pid:%d,ppid:%d\n",getpid(),getppid());
	//	sleep(0.0001);
		printf("after sleeping, and exit!\n");
	}
		printf("cnt:%d\n",cnt);
	}
	return 0;
}
