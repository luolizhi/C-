#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>

int main(int argc, char*argv[])
{
	int fd_listen;
	fd_listen=socket(AF_INET,SOCK_STREAM,0);
	
	if(fd_listen == -1)
	{
		perror("socket");
		exit(1);
	}

	//bind
	struct sockaddr_in seraddr;
	memset(&seraddr,0,sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port  = htons(1234);	//>1024

	seraddr.sin_addr.s_addr = inet_addr("192.168.1.153");
	int ret;
	ret = bind(fd_listen,(const struct sockaddr*)&seraddr,(socklen_t)sizeof(seraddr));
	
	if(ret == -1)
	{
		perror("bind");
		close(fd_listen);
		exit(1);
	}

	//listen
	listen(fd_listen,10);

	//accept
	struct sockaddr_in peeraddr;
	memset(&peeraddr,0,sizeof(peeraddr));
	socklen_t len= sizeof(peeraddr);
	int fd_peer = accept(fd_listen,(struct sockaddr*)&peeraddr,&len);
	
	printf("who:%s:%d\n",inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port));

	if(fd_peer == -1)
	{
		perror("accept");
		close(fd_listen);
		exit(1);
	}
	
	//read
	char buf[1024];

	int readn = read(fd_peer,buf,1023);
	printf("readn:%d,msg:%s\n",readn,buf);

	char *p = "--------------------";
	write(fd_peer,p,strlen(p));

	close(fd_listen);
	close(fd_peer);

	return 0;
}

