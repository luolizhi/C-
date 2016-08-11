/*************************************************************************
	> File Name: socketio.cc
	> Author: lukey
	> Mail: lukey123@foxmail.com 
	> Created Time: Tue 07 Jul 2015 03:13:35 PM CST
 ************************************************************************/

#include"socketio.h"
#include<unistd.h>
#include<errno.h>
#include<sys/socket.h>


namespace lukey
{
ssize_t SocketIO::readn(char *buf, size_t count)
{
	size_t nleft = count;	//剩余的字节数
	size_t nread;	// 返回值
	char *bufp = (char *)buf;//缓冲区的偏移量

	while(nleft > 0)
	{
		nread = ::read(sockfd_, bufp, nleft);
		if(-1 == nread)
		{
			if(errno == EINTR)
				continue;
			return -1;
		}
		else if(0 == nread)
			break;	//eof
		
		nleft -= nread;
		bufp += nread;
	}
	return (count - nleft);
}

ssize_t SocketIO::writen(const char *buf, size_t count)
{
	size_t nleft = count;
	ssize_t nwrite;
	const char *bufp = buf;
	
	while(nleft > 0)
	{
		nwrite = ::write(sockfd_, bufp, nleft);
		if(nwrite <= 0)
		{
			if(nwrite == -1 && errno == EINTR)
				continue;
			return -1;
		}

		nleft -= nwrite;
		bufp += nwrite;
	}

	return count;
}

ssize_t SocketIO::recv_peek(char *buf, size_t len)
{
	int nread;
	do{
		nread = ::recv(sockfd_, buf, len, MSG_PEEK);
	}while(nread == -1 && errno == EINTR);

	return nread;
}

ssize_t SocketIO::readline(char * usrbuf, size_t maxlen)
{
	size_t nleft = maxlen - 1;
	char *bufp = usrbuf;
	size_t total = 0;

	ssize_t nread;
	while(nleft > 0)
	{
		nread = recv_peek(bufp, nleft);
		if(nread <= 0)
			return nread;

		int i;
		for(i = 0; i < nread; i++)
		{
			if(bufp[i] == '\n')
			{
			//找到\n
				size_t nsize = i + 1;
				if(readn(bufp, nsize) != static_cast<ssize_t>(nsize))
					return -1;

				bufp += nsize;
				total += nsize;
				*bufp = 0;
				return total;
			}
		}

		//没有找到\n
		if(readn(bufp, nread) != nread)
			return -1;

		bufp += nread;
		total += nread;
		nleft -= nread;
	}
	*bufp = 0;

	return maxlen - 1;
}


}//end of namespace lueky

