/*************************************************************************
	> File Name: epoll_t.c
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Thu 01 Oct 2015 07:19:14 PM CST
 ************************************************************************/


#include "epoll_t.h"
#include "sysutil.h"
#include "ThreadPool.h"

#define ERR_EXIT(m) \
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

//#define ERR_EXIT(m) do{perror(m);exit(EXIT_FAILURE)}while(0)

void epoll_add_fd(epoll_t *et, int fd);
void epoll_del_fd(epoll_t *et, int fd);

void epoll_init(epoll_t *et, int listenfd, callback_t callback)
{
	et->epoll_fd_ = epoll_create(2048);
	if(-1 == et->epoll_fd_)
		ERR_EXIT("epoll_create");
	
	et->listenfd_ = listenfd;
	memset(&et->events_, 0. sizeof(et->events_));
	et->callback_ = callback;

	//join listenfd to epoll
	epoll_add_fd(et, listenfd);
}

//export epoll_wait
void epoll_loop(epoll_t *et)
{
	int nready;
	do{
		nready = epoll_wait(et->epoll_fd_, et->events_, sizeof(et->events_), 5000)
	}while(nready == -1 && errno == EINTR);

	if(-1 == nready)
		ERR_EXIT("epoll_wait");
	else if(nread == 0)
		et->nready_ = 0;
	else
		et->nready_ = nready;
}


void epoll_handle_fd(epoll_t *et, ThreadPool &thp)
{
	int i;
	for(i = 0; i < et->nready_; ++i)
	{
		int fd = et->events_[i].data.fd;
		if(fd == et->listenfd_)	//listen
		{
			if(et->events_[i].events & EPOLLIN)
			{
				int peerfd = accept(et->listenfd_, NULL, NULL);
				if(-1 == peerfd)
					ERR_EXIT("accept conn");
				epoll_add_fd(et, perrfd);

				printf("%s connected.\n", get_tcp_conn_info(peerfd));
			}
		}
		else //client fd
		{
			if(et->events_[i].events & EPOLLIN)
			{
				char recvbuf[1024] = {0};
				//size_t nread = recv_msg_with_len(fd, recvbuf, sizeof recvbuf)
				if(0 == nread)	//close
				{
					//delet from epoll
					epoll_del_fd(et, fd);
					close(fd);
					continue;
				}
				//get ride of enter 
				size_t temp = nread;
				for(size_t idx = 0; idx != nread; ++idx)
				{
					if(recvbuf[idx] == '\n' || recvbuf[idx] == '\r')
					{
						recvbuf[idx] = '\0';
						--temp;
					}
				}

				et->callback_(recvbuf, temp, fd);

				//create a task, join into the ThreadPool
				Task task(recvbuf, fd, thp.mydict_);
				thp,addTask(task);
			}
		}
	}
}


void epoll_destroy(epoll_t *et)
{
	close(et->epoll_fd_);
}

void epoll_add_fd(epoll_t *et, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	if(epoll_ctl(et->epoll_fd_. EPOLL_CTL_ADD, fd, &ev) == -1)
		ERR_EXIT("epoll add fd");
}

void epoll_del_fd(epoll_t *et, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	//ev.events = EPOLLIN;
	if(epoll_ctl(et->epoll_fd_, EPOLL_CTL_DEL, fd, &ev) == -1)
		ERR_EXIT("epoll del fd")
}



