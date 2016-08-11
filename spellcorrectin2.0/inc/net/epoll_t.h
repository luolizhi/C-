/*************************************************************************
	> File Name: epoll_t.h
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Sat 05 Sep 2015 09:23:02 PM CST
 ************************************************************************/

#ifndef __EPOLL_T__
#define __EPOLL_T__

#include <sys/epoll.h>

class ThreadPool;
#ifdef __cplusplus
extern "C"
{
#endif
	typedef void (*callback_t) (const char *, size_t cnt, int fd);

	typedef struct {
		int epoll_fd_;
		int listenfd_;
		struct epoll_event events_[2048];
		int nready_;	//准备好的数目
		callback_t callback_;	//回调函数
	}epoll_t;

	void epoll_init(epoll_t *et, int listenfd, callback_t callback);
	void epoll_loop(epoll_t *et);
	void epoll_handle_fd(epoll_t *et, ThreadPool & thp);
	void epoll_destroy(epoll_t *et);

#ifdef __cplusplus
}

#endif //end EPOLL_H__
