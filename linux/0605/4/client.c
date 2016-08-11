#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>

int recvn(int sfd,char* buf, int len)
{
	int recv_sum = 0;
	int recv_ret;
	while(recv_sum < len)
	{
		recv_ret = recv(sfd,(char*)buf+recv_sum,len-recv_sum,0);
		recv_sum += recv_ret;
	}

	return recv_sum;
}

int sendn(int sfd,char* buf, int len)
{
	int send_sum = 0;
	int send_ret;
	while(send_sum < len)
	{
		send_ret = send(sfd,(char*)buf+send_sum,len-send_sum,0);
		send_sum += send_ret;
	}
	return send_sum;
}




int main(int argc, char* argv[])
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(argv[1]);
	address.sin_port = htons(atoi(argv[2]));
	len = sizeof(address);

	result = connect(sockfd,(struct sockaddr*)&address,len);

	if(result == -1)
	{
		perror("oops:client1");
		exit(1);
	}

	char buf[1024];

	printf("len\n");
	recv(sockfd,&len,4,0);
	printf("len:%d\n",len);
	recvn(sockfd,buf,len);
	printf("------------------------\n");
	printf("%s\n",buf);
	printf("------------------------\n");

	//get filename
	while(memset(buf,0,1024),fgets(buf,1024,stdin) != NULL){
		if(buf[0] != '\n')
		{
			break;
		}
	}
	
	buf[strlen(buf)-1]='\0';

	len = strlen(buf);
	send(sockfd,&len,4,0);	//send filename's lenth
	sendn(sockfd,buf,len);	//send filename
	
	recv(sockfd,&len,4,0);
	if(len == -1)
	{
		printf("file not exit\n");
		close(sockfd);
		exit(1);
	}


	FILE* fp = fopen(buf,"w");
	while(1)
	{
		recv(sockfd,&len,4,0);
		if(len == 0)
		{
			break;
		}
		memset(buf,0,1024);
		recvn(sockfd,buf,len);
		
		fputs(buf,fp);
	
	}
	printf("over!\n");


	fclose(fp);
	close(sockfd);
	return 0;
}
