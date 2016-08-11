#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/select.h>
#include<sys/time.h>


int main(int argc, char* argv[])
{
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd == -1)
	{
		perror("socket");
		exit(-1);
	}


	//connect

	int fdsend;
	struct sockaddr_in seraddr;
	memset(&seraddr,0,sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(8888);	//server port
	seraddr.sin_addr.s_addr = inet_addr("192.168.1.153");//server ip
	if(0 !=(fdsend= connect(sfd,(struct sockaddr*)&seraddr,sizeof(seraddr))))
	{
		perror("connect");
		exit(1);
	}
	printf("connet succesed.\n");

	//write
	char *p = "hello world";
	write(fdsend,p,strlen(p));

	//read
	char buf[1024];
	memset(buf,0,sizeof(buf));

	int readn = read(fdsend,buf,sizeof(buf)-1);
	printf("readn:%d,msg:%s\n",readn,buf);
	


	//close
	close(fdsend);
	close(sfd);


	/*
	//recive
	char buf[1024];
	memset(buf,0,sizeof(buf));
	if(-1==recv(rs_fd,buf,sizeof(buf),0))
	{
		perror("recv");
		exit(1);
	}
	
	printf("recv:%s\n",buf);

	//send

*/








	return 0;
}
