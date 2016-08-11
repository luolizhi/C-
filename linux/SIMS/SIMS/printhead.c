#include "sims.h"

void printhead(void)
{
	
	pUSR_ACCOUNT user_account;
	system("cls");

	printf("\n*******************************************************************************\n");
	printf("***************Student	Information	Management	System****************\n");
	printf("*******************************************************************************\n\n\n");
	while (1){
		user_account = (pUSR_ACCOUNT)calloc(1, sizeof(pUSR_ACCOUNT));
		printf("enter usr_name:\n");
		//fgets(line, sizeof(line), stdin);
		scanf("%s", user_account->usr_name);
		printf("enter password:\n");
		getch();
		putch("*");
		scanf("%s", user_account->usr_pwd);
		if (enter(user_account)){
			break;
		}
	}
	



}