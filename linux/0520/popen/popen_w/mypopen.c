#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int left, right;
	while(scanf("%d%d",&left,&right)!=EOF){
		FILE* fp = popen("./myadd","w");
		fprintf(fp,"%d %d\n",left, right);
		fclose(fp);
	}
}
