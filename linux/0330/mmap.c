#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
typedef struct stu
{
	int st_id;
	char st_name[20];
	int st_age;
}stu_t,*pstu_t;

void readfile(char* path);

int main(int argc, char* argv[])
{
	readfile(argv[1]);	
	int fd = open(argv[1],O_RDWR);
	struct stat mystat;
	memset(&mystat,0,sizeof(mystat));
	//pstu_t parr[3];
	//memset(parr,0,sizeof(parr));
	pstu_t	parr=mmap(0,sizeof(parr),PROT_READ | PROT_WRITE,fd,	MAP_SHARED,0);
	strcpy(parr[1].st_name,"lisi");
	parr[1].st_age=22;
	msync(parr,mystat.st_size,0);
	munmap(parr,mystat.st_size);
	readfile(argv[1]);
	return 0;
}

void readfile(char* path)
{
	int fd = open(path,O_RDONLY);
	stu_t arr[3];
	memset(arr,0,sizeof(arr));
	read(fd,arr,sizeof(arr));
	int index;
	for(index=0;index<3;index++){
	printf("%-5d%-10s%-5d\n",arr[index].st_id,arr[index].st_name,arr[index].st_age);
	}
	close(fd);
}




/*
void test_mmap()
{
	int fd = open(argv[1],O_RDONLY);
	struct stat mystat;
	memset(&mystat, 0, sizeof(mystat));
	if(-1==lstat(argv[1],&mystat))
	{
		perror("stat");
		exit(1);
	}
//	printf("st_size:%d",mystat.st_size);
	char* pcontent=mmap(NULL,mystat.st_size,PROT_READ,MAP_PRIVATE,fd,0);
	if(pcontent==MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}
	//write(1,pcontent,sizeof(pcontent));
	fprintf(stdout,"%s",pcontent);
	close(fd);
	printf("\n");
	return 0;
	
}
void writefile() 
{
	stu_t arr[3]={{1001,"zhangsan",18},{1003,"li4",19},{1004,"wangwu",-22}};
	int fd = open(argv[1],O_WRONLY|O_CREAT, 0666);
	write(fd,arr,sizeof(arr));

}


 
 
 */
