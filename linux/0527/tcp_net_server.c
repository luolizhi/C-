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
	if(argc != 3)
	{
		printf("error args");
		exit(-1);
	}
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd == -1)
	{
		perror("socket");
		exit(-1);
	}

	//bind
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret = bind(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));
	if(ret == -1)
	{
		perror("bind");
		close(sfd);
		exit(-1);
	}

	//listen
	ret=listen(sfd,10);
	if(ret == -1)
	{
		perror("listen");
		close(sfd);
		exit(-1);
	}
	printf("I have finished listen.\n");
/*
	struct timeval tm;
	tm.tv_sec = 3;
	tm.tv_usec = 0;
	while(1){
		fd_set rfd;
		FD_ZERO(&rfd);
		FD_SET(sfd,&rfd);
		int maxfd = 14;

		ret = select(maxfd,&readfds,NULL,NULL,&tm);
		if(ret == -1){
			perror("select");
			exit(1);
		}
		if(ret > 0){
			int i;
			for(i=0;i<maxfd;i++){
				if(FD_ISSET(i,&rfd))			
			}
		
		
		}
	}
*/


	//accept
	struct sockaddr_in clientaddr;
	memset(&clientaddr,0,sizeof(clientaddr));
	int addrlen = sizeof(struct sockaddr);
	int rs_fd=accept(sfd,(struct sockaddr*)&clientaddr,&addrlen);
	if(rs_fd == -1)
	{
		perror("accept");
		close(sfd);
		exit(-1);
	}
	printf("%s:%d success connet\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

	//read
	char buf[1024];
	memset(buf,0,sizeof(buf));

	int readn = read(rs_fd,buf,sizeof(buf)-1);
	printf("readn:%d,msg:%s\n",readn,buf);
	
	//write
	char *p = "---------------";
	write(rs_fd,p,strlen(p));


	//close
	close(rs_fd);
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
