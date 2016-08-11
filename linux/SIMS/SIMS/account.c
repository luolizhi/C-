#include "sims.h"

void account(struct usr_account_tag *head)
{
	struct usr_account_tag *p;
	p = head;
	FILE *fp;
	fp = fopen("d://usr_account.txt", "wb");
	if (fp == NULL){
		printf("cannot open\n");
		return;
	}
	while (p != NULL){
		fwrite(p, sizeof(struct usr_account_tag), 1, fp);
		p = p->pNext_Usr_Account;
	}
	fclose(fp);

}