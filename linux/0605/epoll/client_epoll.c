#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/epoll.h>

#define MY_ASSERT(flag,msg) do{\
	(flag)||(printf("%s\n",msg),exit(1),0);\
}while(0)

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("serverip  port");
		exit(1);
	}
	int fd_client = socket(AF_INET,SOCK_STREAM,0);
	MY_ASSERT(fd_client != -1, "socket");

	//connect
	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);
	seraddr.sin_port = htons(atoi(argv[2]));

	MY_ASSERT(connect(fd_client,(struct sockaddr*)&seraddr,sizeof(struct sockaddr))==0,"connect");
	
	char buf[1024];
	int sendn;
	while(memset(buf,0,sizeof(buf)),fgets(buf,sizeof(buf),stdin)!=NULL)
	{
		sendn = send(fd_client,buf,strlen(buf),0);
		printf("sendn:%d\n",sendn);
	}
	
	close(fd_client);
	return 0;
}




