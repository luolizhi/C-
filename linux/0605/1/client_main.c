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
	
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = htons(atoi(argv[2]));

	if(-1 == connect(clientfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr)))
	{
		perror("connect");
		exit(1);
	}
	
	//send
	char send_buf[SIZE]="";
	fgets(send_buf,sizeof(send_buf),stdin);
	send(clientfd,send_buf,strlen(send_buf),0);

	//recv
	/*
	char FULL_PATH[SIZE]="";
	sprintf(FULL_PATH,"%s/%s",DOWN_PATH,send_buf);
	FULL_PATH[strlen(FULL_PATH)-1]='\0';
*/
	send_buf[strlen(send_buf)-1]='\0';
	FILE* fp = fopen(send_buf,"w");

	char recv_buf[SIZE] = "";
	recv(clientfd,recv_buf,sizeof(recv_buf)-1,0);
	//printf("recv:%s\n",recv_buf);
	fwrite(recv_buf,1,strlen(recv_buf),fp);
	
	fclose(fp);


	close(clientfd);




	return 0;
}











