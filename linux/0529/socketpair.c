#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>

int main(int argc, char* argv[])
{
	int z;	//status return code
	int sfd[2];		//pair if sockets
	struct msghdr msg;
	struct iovec iov[1];
	char send_buf[100] = "TEST";
	struct msghdr msgr;
	struct iovec iovr[1];
	char recv_buf[100];

	//create a pair of local sockets

	z = socketpair(AF_LOCAL,SOCK_STREAM,0,sfd);

	if(z == -1)
	{
		perror("socketpair");
		exit(1);
	}

	//sendmsg fds[1];
	//struct msghdr msg;
	bzero(&msg,sizeof(msg));
	msg.msg_name = NULL;	//this is a pointer to void* type
	msg.msg_namelen = 0;
	
	iov[0].iov_base = send_buf;
	iov[0].iov_len = sizeof(send_buf);
	
	msg.msg_iov = iov;
	/*
	 msg.msg_iov[0].iov_base = send_buf;
	 msg.msg_iov[0].iov_len = sizeof(send_buf);
	//if have more 
	msg.msg_iov[1].iov_base = send_buf2;
	 msg.msg_iov[1].iov_len = sizeof(send_buf);
	 */

	msg.msg_iovlen = 1;
	
	printf("sendmsg begin...\n");

	z = sendmsg(sfd[1],&msg,0);
	if(z == -1)
	{
		perror("sendmsg");
		exit(1);
	}

	printf("sendmsg success!\n");

	//read from socket sfd[0]

	bzero(&msg,sizeof(msg));
	msgr.msg_name = NULL; 
	msgr.msg_namelen = 0;
	iovr[0].iov_base = &recv_buf;
	iovr[0].iov_len = sizeof(recv_buf);
	msgr.msg_iov = iovr;
	msgr.msg_iovlen = 1;

	z = recvmsg(sfd[0],&msgr,0);
	if(z == -1)
	{
		perror("recvmsg");
		exit(1);
	}

	printf("recvmsg success!\n");

	printf("recvmsg: %s\n",recv_buf);

	//close the sockets

	close(sfd[0]);
	close(sfd[1]);

	puts("Done\n");
	return 0;
}










