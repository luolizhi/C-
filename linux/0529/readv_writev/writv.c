#include<stdio.h>
#include<sys/uio.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{

	ssize_t size;

	char buf1[9];
	char buf2[9];

	struct iovec iov[2];

	int fd1, fd2, fd3;
	fd1 = open(argv[1],O_RDONLY);	//text1	
	fd2 = open(argv[2],O_RDONLY);	//text2
	fd3 = open(argv[3],O_WRONLY);	//text3


	size = read(fd1,buf1,sizeof(buf1));
	printf("%s size is :%d\n",argv[1],size);
	size = read(fd2,buf2,sizeof(buf2));
	printf("%s size is :%d\n",argv[2],size);

	iov[0].iov_base = buf1;
	iov[0].iov_len = sizeof(buf1);

	iov[1].iov_base = buf2;
	iov[1].iov_len = sizeof(buf2);

	size = writev(fd3,iov,2);
	printf("%s size is:%d\n",argv[3],size);

	close(fd1);
	close(fd2);
	close(fd3);

}






