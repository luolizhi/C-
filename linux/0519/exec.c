#include<unistd.h>
#include<stdio.h>
extern char** environ;
void test();

int main(int argc, char* argv[])
{
	printf("befor:-------\n");
	test();
	//	execl("./getpid","./getpid",NULL);
	//execl("/bin/ls","ls","-l",NULL);
	printf("after:+++++++\n");
	return 0;
}

void test()
{
	int index;
	for(index=0;environ[index]!=NULL;index++)
	{
		printf("%d:%s\n",index,environ[index]);
	}
}
