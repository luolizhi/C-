#include"tcp_net_socket.h"

int recvn(int sfd,char buf[],int len)
{
	int recv_sum = 0;
	int recv_ret;
	while(recv_sum < len)
	{
		recv_ret = recv(sfd,(char*)buf+recv_sum,len-recv_sum,0);
		recv_sum +=recv_ret;
	
	}
	return recv_sum;
}

int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("usage:./servertcp ip  port\n");
		exit(1);
	}
	//signalhandler();

	int sfd = tcp_init(argv[1],atoi(argv[2]));	//socket bind listen
	while(1)
	{
		int cfd = tcp_accept(sfd);

		//recive
		char buf[512] = {0}; //=""
		while(memset(buf,0,sizeof(buf)),recv(cfd,buf,sizeof(buf),0)!=-1){
			printf("recive:%s\n",buf);

			//send
			if(send(cfd,"recv success\n",12,0)==-1)
			{
				perror("send");
				close(cfd);
				close(sfd);
				exit(1);
			}
		}
		close(cfd);

	}
	close(sfd);

	return 0;
}
