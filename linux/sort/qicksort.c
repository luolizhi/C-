#include"arr.h"

void qicksort(int a[],int left, int right)
{
		int i, j;
		int temp;
		if(left<right){

				i=left;
				j=right;
				temp=a[left];
				while(i < j){
						while(j>i && a[j]>=temp)
								j--;
						if(i<j){
								a[i] = a[j];
								i++;
						}
						while(i<j && a[i]<temp)
								i++;
						if(i<j){
								a[j] = a[i];
								j--;
						}
				}
				a[i] = temp;
				qicksort(a,left,i-1 );
				qicksort(a,i+1,right);
		}

}
