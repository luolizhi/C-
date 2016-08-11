#include"server_common.h"

int recvn(int sfd,char* buf,int len)
{
	int recv_n;
	int recv_sum=0;
	while(recv_sum < len)
	{
		recv_n = recv(sfd,buf+recv_sum,len-recv_sum,0);
		recv_sum +=recv_n;
	}
	return recv_sum;
}
int sendn(int sfd,char* buf,int len)
{
	int send_sum=0;
	int send_ret;
	while(send_sum < len)
	{
		send_ret = send(sfd,buf+send_sum,len-send_sum,0);
		send_sum += send_ret;
	}
	return send_sum;
}


void showdir(int clientfd,const char* name)
{
	DIR* dir = opendir(name);
	char buf[SIZE]="";
	struct dirent* pent;
	while((pent=readdir(dir))!=NULL)
	{
		if(strcmp(pent->d_name,".")==0 || strcmp(pent->d_name,"..")==0)
		{
			continue;
		}
		strcat(buf,"\n");
		strcat(buf,pent->d_name);
	}
	send(clientfd,buf,strlen(buf),0);

}
