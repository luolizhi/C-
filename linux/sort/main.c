#include"arr.h"

int main(int argc, char* argv[])
{
	int a[N];
	arr_init(a,N);
	printf("qicksort\n");
	arr_show(a,N);
	qicksort(a,0,N-1);//test quiksort
	arr_show(a,N);
	sleep(1);

	arr_init(a,N);
	printf("insertsort\n");
	arr_show(a,N);
	insertsort(a,N);//test insertsort
	arr_show(a,N);
	sleep(1);
	

	arr_init(a,N);
	printf("seletsort\n");
	arr_show(a,N);
	selectsort(a,N);//test selectsort
	arr_show(a,N);

	return 0;
}
