#include"server_common.h"

int main(int argc, char* argv[])	//ip port
{
	if(argc != 3)
	{
		printf("EXE IP PORT\n");
		exit(1);
	}
	//socket
	int serverfd = socket(AF_INET,SOCK_STREAM,0);
	if(serverfd == -1)
	{
		perror("socket");
		exit(1);
	}

	//bind
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = htons(atoi(argv[2]));

	if(-1 == bind(serverfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr)))
	{
		perror("bind");
		exit(1);
	}

	//listen
	if(-1 == listen(serverfd,10))
	{
		perror("listen");
		exit(1);
	}

	while(1)
	{

		//accept
		int clientfd;
		struct sockaddr_in clientaddr;
		socklen_t clientlen = sizeof(clientaddr);

		clientfd = accept(serverfd,(struct sockaddr*)&clientaddr,&clientlen);
		if(clientfd == -1)
		{
			perror("accept");
			exit(1);
		}

		printf("client: ip:%s,port:%d on\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

		if(fork()==0){
			showdir(clientfd,DOWN_PATH);
			//recv
			char recv_buf[SIZE] = "";
			char FULL_PATH[SIZE] = "";

			recv(clientfd,recv_buf,sizeof(recv_buf)-1,0);

			sprintf(FULL_PATH,"%s/%s",DOWN_PATH,recv_buf);
			FULL_PATH[strlen(FULL_PATH)-1] = '\0';
			printf("download file:%s\n",FULL_PATH);

			//open file
			FILE* fp = fopen(FULL_PATH,"r");
			if(fp == NULL)
			{
				perror("fopen");
				exit(1);
			}

			//read file
			char send_buf[SIZE] = "";
			size_t readn;
			readn = fread(send_buf,1,sizeof(send_buf),fp);
			printf("readn:%d\n",readn);

			//send
			size_t sendn;
			sendn = send(clientfd,send_buf,strlen(send_buf),0);
			if(sendn == -1)
			{
				perror("sendn");
				exit(1);
			}

			printf("sendn:%d\n",sendn);
		}
	}
	//close(clientfd);
	close(serverfd);
	//while(1);
	return 0;
}





