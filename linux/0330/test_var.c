#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int g_val1;//BSS
int g_val2=3;

int func(int a, int b);
int main(int argc, char* argv[])
{
	int l_val1;
	int l_val2=33;
	int *p=(int *)calloc(5,sizeof(int));
	char *pstr = "hello world";
	return 0;
}

int func(int a,int b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
