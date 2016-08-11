#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	int sys_ret;

	sys_ret=system("./myadd 1 3");
	printf("res:%d",sys_ret>>8);
	printf("----------------------------------\n");
	return 0;
}
