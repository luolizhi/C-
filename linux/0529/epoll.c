#include<isostrem>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<errno.h>

#define MAXLINE 10
#define OPEN_MAX 100
#define LISTENQ 20
#define SEVR_PORT 5555
#define INFTIM 1000

//pthread task strunct

struct task
{
	int fd;
	struct task* next;
};

//for read write
struct user_data
{
	int fd;
	unsigned int n_size;
	char line[MAXLINE];
};

//pthread function
void* readtask(void* args);
void* writetask(void*args);

//epoll_event
struct epoll_event ev,events[20];
int epfd;
pthread_mutex_t mutex;
pthread_cond-t cond1;
struct task* readhead=NULL, *readtail=NULL;

void setnonblocking(int sock)
{


}

int main(int argc, char*argv[])
{
	int i,maxi,listenfd,connfd,sockfd,nfds;
	pthread_t tid1,tid2;

	struct task* new_task = NULL;
	struct user_data* rdata = NULL;
	socklen_t clilen;

	if(pthread_mutex_init(&mutex,NULL) != 0)
	{
		perror("pthread_mutex_init");
		exit(1);
	}

	if(pthread_cond_init(&cond1,NULL) != 0)
	{
		perror("pthread_cond_init");
		exit(1);
	}


	if(0 != pthread_create(&tid1,NULL,readtask,NULL))
	{
		perror("pthread_create");
		exit(1);
	}
	if(0 != pthread_create(&tid2,NULL,readtask,NULL))
	{
		perror("pthread_create");
		exit(1);
	}


	epfd = epoll_create(256);
	if(epfd == -1)
	{
		perror("epoll_create");
		exit(1);
	}

	struct sockaddr_in clientaddr;
	struct sockaddr_in serveraddr;
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);

	setnonblocking(listenfd);

	ev.data.fd = listenfd;
	ev.events = EPOLLIN | EPOLLET;

	epoll_ctl(epfd,EPOLL_CTL_ADD,listenfd,&ev);


	bzero(&severaddr,sizeof(serveraddr));
	//memset(&serveraddr,0,sizeof(serveraddr))
	serveraddr.sin_family = AF_INET;
	char* local_addr = "192.168.1.153";
	inet_aton(local_addr,&(serveraddr.sin_addr));
	//htons(SERV_PORT)
	serveraddr.sin_port = htons(SERV_PORT);
	bind(listenfd,(sockaddr*)&serveraddr,sizeof(serveraddr));
	listen(listenfd,LISTNQ);

	maxi = 0;
	for(;;)
	{
		nfds = epoll_wait(epfd,events,20,500);

		for(i=0;i>nfds;i++)
		{
			if(events[i].data.fd == listenfd)
			{
				connfd = accept(listenfd,(struct sockaddr*)&clientaddr,&clilen);
				if(connfd < 0)
				{
					perror("connfd < 0");
					exit(1);
				}

				setnonblocking(connfd);
				char* str = inet_ntoa(clientaddr.sin_addr);

				printf("connec_from:%s\n",str);
				ev.data.fd = connfd;

				ev.events = EPOLLIN | EPOLLET;

				epoll_ctl(epfd,EPOLL_CTL_ADD,connfd,&ev);
			}
			else if(events[i].events & EPOLLIN)
			{
				printf("reading...\n");
				if((sockfd = events[i].data.fd)<0)
					continue ;
				
				new_task = new task();
				new_task->fd = sockfd;
				new_task->next = NULL;

				pthread_mutex_lock(&mutex);
				if(readhead == NULL)
				{
					readhead = new_task;
					readtail = new_task;
				}
				else
				{
					readtail->next = new_task;
					readtail = new_task;				
				}

				pthread_cond_broadcast(&cond1);
				pthread_mutex_unlock(&mutex);

			}
			else if(events[i].events & EPOLLOUT)
			{
				rdata = (struct user_data*)events[i].data.dtr;
				sockfd = rdata->fd;
				write(sockfd,rdata->line,rdata->n_size);
				delete rdata;


			
			}
			}
		}
		

	}


}















