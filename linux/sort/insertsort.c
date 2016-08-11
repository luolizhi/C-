#include"arr.h"

void insertsort(int a[],int n)
{
	int i,j,k;
	int temp;
	for(i=1;i<n;i++){
		temp = a[i];
		for(j=0;j<i;j++){
			if(a[j] > temp){
				for(k=i;k>j;k--){
					a[k] = a[k-1];	
				}
			a[k]= temp;
			break;
			}
		}

	}
}
