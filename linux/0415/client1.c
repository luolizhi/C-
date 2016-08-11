#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

//#define PORT 8888
//#define IP "192.168.1.153"

void usr1_handle(int arg)
{
	printf("usr1_handle\n");
	wait(NULL);
	exit(1);
}

int main(int argc,char* argv[])	//host_ip host_port peer_ip perr_port
{
	if(argc!=5)
	{
		printf("host(ip,port),peer(ip,port)\n");
		exit(1);
	}
	//socket
	int sfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sfd == -1)
	{
		perror("socket");
		exit(1);
	}
	//bind
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));
	addr.sin_addr.s_addr = inet_addr(argv[1]);

	if(-1 == bind(sfd,(struct sockaddr*)&addr,sizeof(struct sockaddr)))
	{
		perror("bind");
		exit(1);
	}

	pid_t pid;
	if((pid=fork())==0)	//child recv
	{
		while(1)
		{
			//recvfrom
			int recv_ret;
			char buf[1024]="";

			struct sockaddr_in peeraddr;
			socklen_t len = sizeof(peeraddr);
			recv_ret=recvfrom(sfd,buf,1023,0,(struct sockaddr*)&peeraddr,&len);
			if(recv_ret == -1)
			{
				perror("recvfrom");
				exit(1);
			}
			//
			if(strcmp(buf,"0000")==0)
			{
				kill(getppid(),SIGUSR1);
				printf("over\n");
				//exit(1);
				break;
			}
			printf("ip:%s,port:%d\n",inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port));
			printf("msg:%s\n",buf);
		}
		exit(1);	
	}	

	//sendto
	struct sockaddr_in peeraddr;
	peeraddr.sin_family = AF_INET;
	peeraddr.sin_addr.s_addr = inet_addr(argv[3]);
	peeraddr.sin_port = htons(atoi(argv[4]));

	
	signal(SIGUSR1,usr1_handle);
	char msg[1024];
	while(memset(msg,0,sizeof(msg)),fgets(msg,sizeof(msg)-1,stdin)!=NULL)
		{
			sendto(sfd,msg,strlen(msg),0,(struct sockaddr*)&peeraddr,sizeof(peeraddr));
			
		}
	char* p = "0000";
	sendto(sfd,p,strlen(p),0,(struct sockaddr*)&peeraddr,sizeof(peeraddr));
	kill(pid,SIGUSR2);
	close(sfd);


	return 0;
}










