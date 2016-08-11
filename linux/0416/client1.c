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

#define MSG_ON 1
#define MSG_OFF 2
#define MSG_NOR 3
#define SIZE 1024

typedef struct msg
{
	int msg_type;
	char msg_buf[SIZE];
}msg_t, *pmsg_t;


void usr1_handle(int arg)
{
	printf("usr1_handle\n");
	exit(1);
}
int main(int argc,char* argv[])	//host_ip host_port server_ip server_port
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

	msg_t clientmsg;
	pid_t pid;
	if((pid=fork())==0)	//child recv
	{
		signal(2,usr1_handle);
		while(1)
		{
			//recvfrom
			char buf[1024]="";
			int recv_ret;
			memset(&clientmsg,0,sizeof(msg_t));

			struct sockaddr_in peeraddr;
			socklen_t len = sizeof(peeraddr);
			recv_ret=recvfrom(sfd,&buf,sizeof(buf),0,(struct sockaddr*)&peeraddr,&len);
			if(recv_ret == -1)
			{
				perror("recvfrom");
				exit(1);
			}

			//printf("ip:%s,port:%d\n",inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port));
			printf("msg:%s\n",buf);
		}
		exit(1);	
	}	

	//sendto
	struct sockaddr_in peeraddr;
	peeraddr.sin_family = AF_INET;
	peeraddr.sin_addr.s_addr = inet_addr(argv[3]);
	peeraddr.sin_port = htons(atoi(argv[4]));

	//send_on_msg
	memset(&clientmsg,0,sizeof(msg_t));
	clientmsg.msg_type = MSG_ON;

	sprintf(clientmsg.msg_buf,"%s:%s on!\n",argv[1],argv[2]);
	//printf("%s\n",clientmsg.msg_buf);
	sendto(sfd,&clientmsg,sizeof(clientmsg),0,(struct sockaddr*)&peeraddr,sizeof(peeraddr));

	while(memset(&clientmsg,0,sizeof(clientmsg)),fgets(clientmsg.msg_buf,sizeof(clientmsg.msg_buf)-1,stdin)!=NULL)
	{
		clientmsg.msg_type = MSG_NOR;
		sendto(sfd,&clientmsg,sizeof(msg_t),0,(struct sockaddr*)&peeraddr,sizeof(peeraddr));
	}
	//send_off_msg
	memset(&clientmsg,0,sizeof(msg_t));
	clientmsg.msg_type = MSG_OFF;

	sprintf(clientmsg.msg_buf,"%s:%s off!\n",argv[1],argv[2]);
	printf("%s\n",clientmsg.msg_buf);
	sendto(sfd,&clientmsg,strlen(clientmsg.msg_buf),0,(struct sockaddr*)&peeraddr,sizeof(peeraddr));


	kill(pid,2);
	wait(NULL);

	close(sfd);


	return 0;
}










