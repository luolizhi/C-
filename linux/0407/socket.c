#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
	char ip[] = "192.168.0.101";

	struct in_addr myaddr;
	/*inet_aton*/
	int ret = inet_aton(ip,&myaddr);
	printf("s_addr:%x\n",myaddr.s_addr);


	/*inet_addr*/
	printf("inet_addr:%x\n",inet_addr(ip));

	/*inet_pton*/
	ret = inet_pton(AF_INET,ip,&myaddr);
	printf("inet_pton:%x\n",myaddr.s_addr);

	myaddr.s_addr = 0xac100ac4;
	/*inet_ntoa*/
	printf("inet_ntoa:%s\n",inet_ntoa(myaddr));

	/*inet_ntop*/
	inet_ntop(AF_INET,&myaddr,ip,16);
	puts(ip);

	return 0;

}
