#include"tcp_net_socket.h"

int main(int argc, char* argv[])
{
	if(argc < 3){
		printf("usage:./servertcp  ip  port\n");
		exit(1);
	}

	int sfd = tcp_connect(argv[1],atoi(argv[2]));
	//ip "192.168.1.153"  port 8888

	//send
	char buf[512] = {0};

	while(memset(buf,0,sizeof(buf)),fgets(buf,sizeof(buf)-1,stdin)!=NULL){
			send(sfd,buf,sizeof(buf),0);


			//recv
			memset(buf,0,sizeof(buf));
			recv(sfd,buf,sizeof(buf)-1,0);
			printf("recv:%s\n",buf);

			close(sfd);
		}
			return 0;
			}
