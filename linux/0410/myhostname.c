#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char* argv[])
{
	char* host = "www.mi.com";
	struct hostent* pent;
	if((pent=gethostbyname(host)) == NULL)
	{
		perror("gethost");
		exit(1);
	}
	printf("h_name:%s\n",pent->h_name);
	int index;
	for(index=0;pent->h_aliases[index]!=NULL;index++){
		printf("pent->h_aliases[%d]:%s\n",index,pent->h_aliases[index]);
	}
	printf("h_addrtype:%d\n",pent->h_addrtype);
	printf("h_length:%d\n",pent->h_length);
	for(index=0;pent->h_addr_list[index]!=NULL;index++){
		printf("%d:%s\n",index,inet_ntoa(*(struct in_addr*)pent->h_addr_list[index]));
	}
	

	return 0;
}
