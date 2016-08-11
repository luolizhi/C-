#include "sims.h"

USR_ROLE system_menu(USR_ROLE type)
{
	int number;
	int search_number;
	if (type == 1){
		system("cls");
		printf("\n*******************************************************************************\n");
		printf("***************Student	Information	Management	System*****************\n");
		printf("*******************************************************************************\n");
		printf("\n\n\t\t1. search	student information");
		printf("\n\t\t2. add		student information");
		printf("\n\t\t3. update	student information");
		printf("\n\t\t4. delete	student information");
		printf("\n\t\t5. add		user account");
		printf("\n\t\t6. update	user account");
		printf("\n\t\t7. delete	user account");
		printf("\n\t\t8. search	user account");
		printf("\n\t\t9. exit");
		printf("\n\n\nselect a number between 1--9:");
		return type;
	}
	else if (type == 2)
	{
		system("cls");
		printf("\n*******************************************************************************\n");
		printf("***************Student	Information	Management	System****************\n");
		printf("*******************************************************************************\n");
		printf("\n\n\t\t1. search	student information");
		/*
		printf("\n\t\t2. add		student information");
		printf("\n\t\t3. update	student information");
		printf("\n\t\t4. delete	student information");
		printf("\n\t\t5. add		user account");
		printf("\n\t\t6. update	user account");
		printf("\n\t\t7. delete	user account");
		printf("\n\t\t8. search	user account");
		*/
		printf("\n\t\t9. exit");
		printf("\n\n\nselect a number:");
		return type;
	}
	else
	{
		return;
	}
}



USR_ROLE  search_menu(USR_ROLE type)
{
	system("cls");
	if (type == 1){
		printf("\n0. search	all");
		printf("\n1. search	by id");
		printf("\n2. search	by name");
		printf("\n3. return");
		printf("\nselect a number:");
	}
	else
	{
		printf("\n1. search	by id");
		printf("\n2. search	by name");
		printf("\n3. return");
		printf("\nselect a number:");
		
	}
	return type;
}

void account_search_menu(void)
{
	system("cls");
	printf("\n0. search	all account");
	printf("\n1. search	account by name");
	printf("\n2. exit");
	printf("\nselect a number:");

}

void usr_infor_delete_menu(void)
{
	system("cls");
	printf("\n1. delete	by id");
	printf("\n2. delete	by name");
	printf("\n3. return");
	printf("\nselect a number:");
	fflush(stdin);
}