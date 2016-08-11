#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<pthread.h>
#include<arpa/inet.h>

#define DEFAULT_SVR_PORT 2828
#define FILE_MAX_LEN 64
char filename[FILE_MAX_LEN+1];

static void* handle_client(void* arg)
{
	int sock = (int)arg;
	char buf[1024];
	int len;
	printf("begin send\n");
	FILE* file = fopen(filename,"r");
	if(file == NULL)
	{
		close(sock);
		exit(1);
	}

	//send filename
	if(send(sock,filename,FILE_MAX_LEN,0) == -1)
	{
		perror("send file name");
		goto EXIT_THREAD;
	}
	printf("begin send file%s...\n",filename);

	//send file content
	while(!feof(file))
	{
		len = fread(buf,1,sizeof(buf),file);
		printf("server read %s,len %d\n",filename,len);
		if(send(sock,buf,len,0)<0)
		{
			perror("send file");
			goto EXIT_THREAD;
		}
	}
EXIT_THREAD:
	if(file)
		fclose(file);
	close(sock);

}


int main(int argc, char* argv[])
{
	int sockfd, new_fd;

	int sin_size, numbytes;
	pthread_t cli_thread;
	unsigned short port;

	if(argc < 2)
	{
		printf("need a filename without path\n");
		exit;	
	}

	strncpy(filename,argv[1],FILE_MAX_LEN);
	port = DEFAULT_SVR_PORT;
	if(argc >= 3)
	{
		port = (unsigned short)atoi(argv[2]);
	}

	//TCP
	//socket
	if((sockfd=socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		perror("socket");
		exit(1);
	}

	// set port 2828 listen any ip
	struct sockaddr_in my_addr, their_addr;
	memset(&my_addr,0,sizeof(struct sockaddr));
	my_addr.sin_family = AF_INET;	//ipv4
	my_addr.sin_port = htons(port);
	my_addr.sin_addr.s_addr = INADDR_ANY;

	//bind
	if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr)) == -1)
	{
		perror("bind");
		goto EXIT_MAIN;
	}

	//listen
	if(listen(sockfd,10)==-1)
	{
		perror("listen");
		goto EXIT_MAIN;
	}
	printf("#@listen port %d\n",port);

	//
	while(1)
	{
		sin_size = sizeof(struct sockaddr_in);
		printf("server waiting ...\n");
		if((new_fd=accept(sockfd,(struct sockaddr*)&their_addr,&sin_size))==-1)
		{
			perror("accept");
			goto EXIT_MAIN;
		}

		printf("---client(ip=%s:port=%d)request\n",inet_ntoa(their_addr.sin_addr),ntohs(their_addr.sin_port));

		pthread_create(&cli_thread,NULL,handle_client,(void*)new_fd);
	}
	//close socket
EXIT_MAIN:
	close(sockfd);

	return 0;

}










