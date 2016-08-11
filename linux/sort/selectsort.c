//#include"arr.h"

void selectsort(int a[], int n)
{
	int i, j, k;
	int min;
	for(i=0;i<n;i++){
		k = i;
		for(j=i;j<n;j++){
			if(a[j]<a[k]){
				k = j;
			}
		}
		if(k!=i){
			min = a[i];
			a[i] = a[k];
			a[k] = min;
		}
	}
	
}
