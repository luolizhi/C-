#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
int main(int argc,char* argv[])
{
	DIR* pdir;
	struct dirent * pent;
	struct stat  my_stat;
	int i;
	char path[256];
	pdir = opendir(argv[1]);
	if(pdir==NULL)
	{
		perror("opendir");
		exit (1);
	}
	while((pent = readdir(pdir))!=NULL){
//	printf("inode:%ld\n",pent->d_ino);
//	printf("offset:%d",pent->d_off);
//	printf("reclen:%d\n",pent->d_reclen);
//	printf("type:%u\n",pent->d_type);
	//	printf("name:%s\n",pent->d_name);
		memset(path,0,256);
		sprintf(path,"%s/%s",argv[1],pent->d_name);
		memset(&my_stat,0,sizeof(my_stat));
		i=stat(path,&my_stat);
		if(i==-1)
		{
			perror("stat");
			exit(1);
		}
		printf("%04x %d %s %s %d %u ",my_stat.st_mode,my_stat.st_nlink,getpwuid(my_stat.st_uid)->pw_name,getgrgid(my_stat.st_gid)->gr_name,my_stat.st_size ,my_stat.st_mtime);
		printf(" %s\n",pent->d_name);
	}
	closedir(pdir);
	return 0;
}
