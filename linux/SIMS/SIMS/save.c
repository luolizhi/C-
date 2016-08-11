#include "sims.h"
void save(pUSR_INFOR arr, int len)
{
	FILE *fp;
	int i;
	if ((fp = fopen("d://Usr_infor.txt", "ab")) == NULL){
		printf("cannot open the file\n");
		return;
	}
	for (i = 0; i < len; i++){
		if (fwrite(&arr[i], sizeof(USR_INFOR), 1, fp) != 1)
			printf("write error\n");
	}
	fclose(fp);
}