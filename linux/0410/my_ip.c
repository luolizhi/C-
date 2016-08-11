#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc,char* argv[])
{
	char *s = "192.168.1.1";
	char *str6 = "00:00:"
	struct in_addr inp;
	struct in6_addr addr3; 
	int ret;
	ret = inet_aton(s,&inp);
	if(ret==0)
	{
		perror("aton");
		exit(-1);
	}
	printf("inp:%08x\n",inp.s_addr);
	
	char *ip = inet_ntoa(inp);
	
	struct in_addr  addr;
	addr.s_addr = inet_addr(s);
	printf("inp:%08x\n",addr.s_addr);
	
	struct in_addr addr2;
	if(1!=inet_pton(AF_INET,s,&addr2))
		{
			perror("inet_pton");
			exit(-1);
			}
	printf("inp:%08x\n",addr2.s_addr);


	return 0;
}

