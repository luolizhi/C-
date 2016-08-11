#include"head.h"

void fun(char* left, char * right)
{
	//left = realloc((strlen(left) + strlen(right))*sizeof(char *),sizeof(left));

	printf("before:%s\n", left);
	strcat(left, right);
	printf("after:%s\n", left);
}