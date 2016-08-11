#include "sims.h"
void create(void)
{
	char ch;
	char ok;
	int i;
	USR_ACCOUNT pusr_account[2];
	FILE *fp;

	if ((fp = fopen("d://usr_account.txt", "w")) == NULL){
		printf("cannot open file\n");
		return;
	}
	scanf("%s%s%d", pusr_account[0].usr_name, pusr_account[0].usr_pwd, &pusr_account[0].usr_role);
	if (fwrite(&pusr_account[0], sizeof(USR_ACCOUNT), 1, fp) != 1)
		printf("file write error\n");
	fclose(fp);



	//return head;
}