#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<arpa/inet.h>
#include<dirent.h>

#define DOWN_PATH "/home/luolizhi/Downloads"

void show(int sfd);

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
void handle_request(int sfd)
{
	show(sfd);
	char full_path[256]="";
	char target_file[128] = "";
	int len;
	recv(sfd,&len,4,0);	//recv lenth of sending file
	recvn(sfd,target_file,len);
	printf("down file:%s\n",target_file);
	sprintf(full_path,"%s/%s\n",DOWN_PATH,target_file);
	//read 
	printf("full_path:%s\n",full_path);
	
	full_path[strlen(full_path)-1]='\0';
	FILE* fp = fopen(full_path,"r");

	//file not exsit send -1 to client
	if(fp == NULL)
	{
		perror("fopen..");
		len=-1;
		send(sfd,&len,4,0);
		close(sfd);
		return;
	}
	len =1;
	send(sfd,&len,4,0);


	char msg[1024];
	//int len;
	while(memset(msg,0,1024),fgets(msg,1024,fp)!=NULL)
	{
		len=strlen(msg);
		send(sfd,&len,4,0);

		sendn(sfd,msg,len);
	}
	len = 0;
	send(sfd,&len,4,0);
	close(sfd);
}

int main(int argc, char* argv[])
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	
	if(argc != 3)
	{
		printf("wrong argc");
		exit(1);
	}
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr((argv[1]));
	server_address.sin_port = htons(atoi(argv[2]));
	server_len =  sizeof(server_address);
	bind(server_sockfd,(struct sockaddr*)&server_address,server_len);

	listen(server_sockfd,10);

	
	client_len = sizeof(client_address);
	
	while(1){
		printf("server waiting...\n");
	
		client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_address,&client_len);
		
		printf("%s:%d,connect!\n",inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port));

		handle_request(client_sockfd);
	
	}
	close(server_sockfd);
	
	return 0;
}


void show(int sfd)
{

	DIR* pdir;
	pdir = opendir(DOWN_PATH);
	if(pdir == NULL)
	{
		perror("opendir");
		exit(1);
	}

	struct dirent* pent;
	char buf[1024]="";
	int len;
	while((pent = readdir(pdir)) != NULL)
	{
		if(strcmp(".",pent->d_name)==0 || strcmp("..",pent->d_name)==0)
		{
			continue;
		}
		strcat(buf,"\n");
		strcat(buf,pent->d_name);
	}

	len = strlen(buf);
	send(sfd,&len,4,0);
	sendn(sfd,buf,len);


}




