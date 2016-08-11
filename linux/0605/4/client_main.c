#include"client_common.h"

int main(int argc, char* argv[])	//serverip port
{
	if(argc != 3)
	{
		printf("EXE IP PORT");
		exit(1);
	}

	//socket
	int clientfd = socket(AF_INET,SOCK_STREAM,0);
	if(clientfd == -1)
	{
		perror("clientfd");
		exit(1);
	}

	//connect
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = htons(atoi(argv[2]));

	if(-1 == connect(clientfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr)))
	{
		perror("connect");
		exit(1);
	}

	char recv_buf[MAX] = "";

	recv(clientfd,recv_buf,sizeof(recv_buf)-1,0);
	printf("--------------------\n");	//download file name
	puts(recv_buf);
	printf("--------------------\n");

	//send
	char send_buf[SIZE]="";
	int filelen;
	while(memset(send_buf,0,sizeof(send_buf)),fgets(send_buf,sizeof(send_buf)-1,stdin)!= NULL)
	{	
		send(clientfd,send_buf,strlen(send_buf),0);

		send_buf[strlen(send_buf)-1]='\0';
		int recvnum;

		memset(recv_buf,0,sizeof(recv_buf));
		recvnum = recv(clientfd,recv_buf,sizeof(recv_buf)-1,0);
		if(strcmp(recv_buf,"10000")==0)
		{
			printf("the file %s not exit in the download file.\n",send_buf);
			continue;
		}else
		{
			FILE* fp = fopen(send_buf,"w+");

			if(fp==NULL)
			{
				perror("fp");
				exit(1);
			}
			printf("recvnum:%d\n",recvnum);
			fwrite(recv_buf,1,strlen(recv_buf),fp);
			fclose(fp);
		}
		printf("the file:%s already download!\n",send_buf);
	}
	printf("over!\n");

	close(clientfd);




	return 0;
}

