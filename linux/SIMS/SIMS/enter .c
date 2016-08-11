#include "sims.h"
int  enter(pUSR_ACCOUNT usr)
{
	pUSR_ACCOUNT pusr;	//这个指针如何指向默认的账户信息，没有初始化	
	pUSR_ACCOUNT pusr_account;
	int i = 0;
	int cont = 0;				//记录输入密码错误的次数
	FILE *fp;
	pusr_account = (pUSR_ACCOUNT)calloc(1, sizeof(pUSR_ACCOUNT));
	/*
	memset(pusr_account, 0, sizeof(pUSR_ACCOUNT));
	*(pusr_account->usr_name) = "admin";
	*(pusr_account->usr_pwd) = "admin";
	pusr_account->usr_role = 1;
	pusr_account->pNext_Usr_Account = NULL;
	*/
	pusr = usr;
	if ((fp = fopen("d://usr_account.txt", "r")) == NULL){
		printf("file cannot open\n");
	}
	//fwrite(pusr_account, sizeof(pUSR_ACCOUNT), 1, fp);
	fread(pusr_account, sizeof(pUSR_ACCOUNT), 1, fp);
	if (strcmp(pusr->usr_name, pusr_account->usr_name) == 0 && strcmp(pusr->usr_pwd, pusr_account->usr_pwd) == 0){
		if (pusr_account->usr_role)
			printhead1();
		else
			printhead2();
		return 1;
	}
	else
		return 0;


	/*
	while (strcmp(purs[i]->usr_name, usr_name) != 0){
		i++;
	}
	if (i < M){
		if (strcmp(purs[i]->usr_pwd, usr_pwd) == 0){
			//usr_role  为1是管理员
			if (purs[i]->usr_role){
				printhead1();
			}
			else
				printhead2();
		}
		else{
			do{
				printf("password wrong.\n");
				cont++;
				fflush(stdin);
				printf("enter password:\n");
				gets(usr_pwd);
				if (strcmp(purs[i]->usr_pwd, usr_pwd) == 0){
					//usr_role  为1是管理员
					if (purs[i]->usr_role){
						printhead1();
					}
					else
						printhead2();
					break;		//跳出do while 循环
				}
			} while (cont < 3);
			if (cont == 3)
				exit;	
		}
	

	}
	else{
		exit;
	}
	*/

	
}