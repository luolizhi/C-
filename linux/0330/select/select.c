#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/ioctl/h>
#include<unistd.h>

#define TRUE	1
#define FALSE	0


#define MYPORT 88960  //the port users will be connecting to 

#define BACKLOG	10 //how mang pending connections queue will hold

#define BUF_SIZE 200

int fd_A[BACKLOG];	//accepted connection fd
int conn_amount;	//current connection amount

void showclient()
{
	int i;
	printf("client amount :%d\n",conn_amount);
	for(i=0;i<BACKLOG;I++){
		printf("[%d]:%d ",i,fd_A[i]);
	}
	printf("\n\n");
}

int main(int argc, char* argv[])
{
	int i,len,rc,on = TRUE;
	int listen_sd, new_sd=0,max_sd;
	int desc_ready;
	char buffer[80];
	int close_conn, end_server = FALSE;
	struct sockaddr_in server_addr;
	struct timeval timeout;
	struct fd_set master_set, working_set;

	//Listen
	listen_sd = socket(AF_INET,SOCK_STREAM,0);
	if (listen_sd < 0)
	{
		perror("socket() failed");
		exit(-1);
	}

	//Set socket options
	rc = setsockopt(listen_sd,SOL_SOCKET,SO_REUSERADDR,(char*)&on,sizeof(on));
	if(rc < 0)
	{
		perror("setsocket() failed");
		close(listen_sd);
		exit(-1);
	}

	//Set IO control
	rc = icotl(listen_sd,FIONBIO,(char*)&on);
	if(rc < 0)
	{
		perror("icotl() failed");
		close(listen_sd);
		exit(-1);
	}
	
	//Bind



}











	
