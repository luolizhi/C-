#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define MY_ASSERT(flag,msg) do{\
		(flag) || ((printf("%s\n",msg)),exit(1),0);\
	}while(0)

int main(int argc, char* argv[])	//ip  port
{
	if(argc < 3)
	{
		printf("wrong argc(ip  port)\n");
	}

	int fd_client;
	MY_ASSERT((fd_client=socket(AF_INET,SOCK_STREAM,0))!= -1,"socket init");

	struct sockaddr_in seraddr;
	memset(&seraddr,0,sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(argv[2]));
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);

	//MY_ASSERT(connect(fd_client,(struct sockaddr*)&seraddr,sizeof(struct sockaddr))==0,"connect failed");
	connect(fd_client,(struct sockaddr*)&seraddr,sizeof(struct sockaddr));


	char buf[1024];
	while(memset(buf,0,sizeof(buf)),fgets(buf,sizeof(buf),stdin)!=NULL)
	{
		send(fd_client,buf,strlen(buf),0);
	}
	




	return 0;
}

