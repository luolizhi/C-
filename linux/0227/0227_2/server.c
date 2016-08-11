#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define MY_ASSERT(flag,msg) \
	do {\
		(flag) || ((printf("%s\n",msg)),exit(1),0);\
	}while(0)

int main(int argc, char* argv[])	//ip  port
{
	if(argc < 3)
	{
		printf("wrong argc(ip  port)\n");
	}
	
	//printf("ip:%s\nport:%s\n",argv[1],argv[2]);

	int fd_listen, fd_client;
	MY_ASSERT((fd_listen=socket(AF_INET,SOCK_STREAM,0))!= -1,"socket init");

	//bind
	struct sockaddr_in seraddr;
	memset(&seraddr,0,sizeof(seraddr));
	
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(argv[2]));
	seraddr.sin_addr.s_addr=inet_addr(argv[1]);
	MY_ASSERT(bind(fd_listen,(struct sockaddr*)&seraddr,sizeof(seraddr))==0,"bind failed");
	
	//bind(fd_listen,(struct sockaddr*)&seraddr,sizeof(struct sockaddr));


	MY_ASSERT(listen(fd_listen,10)==0,"listen");
	//listen(fd_listen,10);

	fd_client = accept(fd_listen,NULL,NULL);
	char buf[1024];

	while(1)
	{
		memset(buf,0,sizeof(buf));
		if(recv(fd_client,buf,sizeof(buf),0)==0)
		{
			printf("a client exit\n");
			close(fd_client);		
		}
		puts(buf);
	}



	return 0;
}










