#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<signal.h>

#define MSG_ON 1
#define MSG_OF 2
#define MSG_NOR 3
#define SIZE 1024


typedef struct msg
{
	int msg_type;
	char msg_buf[SIZE];
}msg_t,*pmsg_t;

typedef struct node
{
	struct sockaddr_in nd_client;
	struct node* nd_next;
}node_t,*pnode_t;

typedef void (*pfun_t)(int, struct sockaddr_in*, char*);

typedef void (*phandle_t)(int sfd, pnode_t* pphead, char* msg,struct sockaddr_in* fromaddr,pfun_t send_fun);

void link_insert(pnode_t* pphead, struct sockaddr_in* peeraddr);

void link_insert(pnode_t* pphead, struct sockaddr_in* peeraddr);

void msg_send(int sfd,struct sockaddr_in* peeraddr, char* msg);
void link_visit(pnode_t* pphead,pfun_t send_func,int sfd,char* msg);

void msg_on_handle(int sfd,pnode_t* pphead,char* msg,struct sockaddr_in* fromaddr,pfun_t send_func);
void msg_off_handle(int sfd,pnode_t* pphead,char* msg,struct sockaddr_in* fromaddr,pfun_t send_func);
void msg_normal_handle(int sfd,pnode_t* pphead,char* msg,struct sockaddr_in* fromaddr,pfun_t send_func);
//msg_on:add into link tell them on
//msg_off:
//msg_nor:

int main(int argc,char* argv[])	//ip port
{
	if(argc != 3)
	{
		printf("EXE IP PORT");
		exit(1);
	}
	
	pnode_t plist = NULL;
	phandle_t handle_arr[4]={NULL,&msg_on_handle,&msg_off_handle,&msg_normal_handle};
	//socket
	int sfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sfd == -1)
	{
		perror("socket");
		exit(1);
	}

	//bind
	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);
	seraddr.sin_port = htons(atoi(argv[2]));
	if(-1 == bind(sfd,(struct sockaddr*)&seraddr,sizeof(struct sockaddr)))
	{
		perror("bind");
		close(sfd);
		exit(1);
	}

	//recvfrom
	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(clientaddr);
	msg_t clientmsg;

	while(1)
	{
		memset(&clientaddr,0,sizeof(clientaddr));
		memset(&clientmsg,0,sizeof(clientmsg));
		recvfrom(sfd,&clientmsg,sizeof(clientmsg),0,(struct sockaddr*)&clientaddr,&len);

//typedef void (*phandle_t)(int sfd, pnode_t pphead, char* msg,struct sockaddr_in* fromaddr,pfun_t send_fun);
	
		(*handle_arr[clientmsg.msg_type])(sfd,&plist,clientmsg.msg_buf,&clientaddr,&msg_send);
	}






	return 0;
}


//insert at head
void link_insert(pnode_t* pphead, struct sockaddr_in* peeraddr)
{
	pnode_t pnew = (pnode_t)calloc(1,sizeof(node_t));
	pnew->nd_client = *peeraddr;
	
	pnew->nd_next = *pphead;
	*pphead = pnew;
}
//
void link_delet(pnode_t* pphead, struct sockaddr_in* peeraddr)
{
	pnode_t pcur, ppre;
	pcur = *pphead;
	ppre = NULL;
	while(pcur)
	{
		if(pcur->nd_client.sin_port == peeraddr->sin_port && pcur->nd_client.sin_addr.s_addr==peeraddr->sin_addr.s_addr)
		{
			break;
		}
		ppre = pcur;
		pcur = pcur->nd_next;
	}
	if(pcur)
	{
		if(ppre==NULL)
		{
			*pphead = pcur->nd_next;
			free(pcur);
		}
		else
		{
			ppre->nd_next = pcur->nd_next;
			free(pcur);
		}
	
	}
}

void msg_send(int sfd,struct sockaddr_in* peeraddr, char* msg)
{
	sendto(sfd,msg,strlen(msg),0,(struct sockaddr*)peeraddr,sizeof(*peeraddr));
}
//
void link_visit(pnode_t* pphead,pfun_t send_func,int sfd,char* msg)
{
	pnode_t pcur = *pphead;
	while(pcur)
	{
		(*send_func)(sfd,&pcur->nd_client,msg);
		pcur = pcur->nd_next;
	}

}
//
void msg_on_handle(int sfd,pnode_t* pphead,char* msg,struct sockaddr_in* fromaddr,pfun_t send_func)
{
	link_insert(pphead,fromaddr);

	link_visit(pphead,send_func,sfd,msg);
}
void msg_off_handle(int sfd,pnode_t* pphead,char* msg,struct sockaddr_in* fromaddr,pfun_t send_func)
{
	link_delet(pphead,fromaddr);
	link_visit(pphead,send_func,sfd,msg);
}
//
void msg_normal_handle(int sfd,pnode_t* pphead,char* msg,struct sockaddr_in* fromaddr,pfun_t send_func)
{
	link_visit(pphead,send_func,sfd,msg);
}









