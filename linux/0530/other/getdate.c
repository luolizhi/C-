#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	char* host;
	int sockfd;
	int len,result;
	struct sockaddr_in address;
	struct hostent *hostinfo;
	struct servent* servinfo;
	char buffer[128];

	if(argc == 1)
	{
		host = "localhost";
	}
	else
	{
		host = argv[1];
	}

	hostinfo = gethostbyname(host);
	if(!hostinfo)
	{
		perror("host");
		exit(1);
	}

	servinfo = getservbyname("daytime","tcp");
	if(!servinfo)
	{
		perror("daytime");
		exit(1);
	}

	printf("daytime port is %d\n",ntohs(servinfo->s_port));


	sockfd = socket(AF_INET,SOCK_STREAM,0);

	//connect
	address.sin_family = AF_INET;
	address.sin_port = servinfo->s_port;
	address.sin_addr = *(struct in_addr *)&hostinfo->h_addr_list;
	len = sizeof(address);
	if(result == -1)
	{
		perror("getdate");
		exit(1);
	}

	result = read(sockfd,buffer,sizeof(buffer));
	buffer[result] = '\0';
	printf("read %d bytes: %s\n",result,buffer);

	close(sockfd);
	return 0;


}













