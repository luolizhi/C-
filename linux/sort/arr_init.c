#include "arr.h"
void arr_init(int a[],int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++){
		a[i]=rand()%100;
	}
}

