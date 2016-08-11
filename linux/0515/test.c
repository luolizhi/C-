#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
void printname(char* dir, int width);


int main(int argc, char *argv[])
{

//	 DIR *root;
//  	 struct dirent *dir;
//	 root = opendir(argv[1]);
//	while((dir=readdir(root))!=NULL)
//	{
//		printf("the dirname is %s\n",dir->d_name);
//	}
	int i =0;
	printname(argv[1],4);

	return 0;

}

void printname(char* dir, int width)
{	
	DIR *root;
	char str[1024]={0};
	unsigned char dirtype='d';
	struct dirent *rent;
	printf(" %s\n",dir);
   	root = opendir(dir);
	while((rent=readdir(root))!=NULL)
	{
		if((strcmp(rent->d_name,".")==0)||(strcmp(rent->d_name,"..")==0))
		{
			continue;
		}
//		printf("the type is %d\n",rent->d_type);
		if(rent->d_type == 4)
		{
	
			printf("%*s%s\n",width,"",rent->d_name);
			sprintf(str,"%s%s%s",dir,"/",rent->d_name);
			printname(str,width+4);
		}
		else
		{
			printf("%*s%s\n",width,"",rent->d_name);
		}
	}
}

