#include "sims.h"

USR_ROLE system_init(pUSR_ACCOUNT *account_head, pUSR_INFOR *usr_infor_head, char *addres)
{
	pUSR_ACCOUNT pAccount, pAcc_cur;
	pUSR_INFOR pUsrinfor, pUsr_cur, ppre;
	FILE *fp_config, *fp_usr_account, *fp_usr_infor;
	char line[LEN];
	char account_name[LEN];
	char account_pwd[LEN];
	int j = 0;//记录密码长度
	if ((fp_config = fopen(addres, "r")) == NULL){
		printf("open failed!\n");
		return 1;
	}
	//加载账户信息
	
	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), fp_config);
	line[strlen(line) - 1] = '\0';
	fp_usr_account = fopen(line, "r");
	if (fp_usr_account == NULL){
		printf("open failed!\n");
		return 1;
	}
	while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), fp_usr_account) != NULL){
		pAccount = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
		sscanf(line, "%s%s%d", pAccount->usr_name, pAccount->usr_pwd, &pAccount->usr_role);
		pAccount->pNext_Usr_Account = *account_head;
		*account_head = pAccount;
	}
	pAcc_cur = *account_head;
		//加载学生信息
		memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), fp_config);
	//line[strlen(line) - 1] = '\0';
	fp_usr_infor = fopen(line, "r");
	if (fp_usr_infor == NULL){
		printf( "open failed!\n");
		return 1;
	}
	while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), fp_usr_infor) != NULL){
		pUsrinfor = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
		sscanf(line, "%d%s%d%lf", &pUsrinfor->usr_id, pUsrinfor->usr_name, &pUsrinfor->usr_course_id, &pUsrinfor->usr_course_score);
		pUsr_cur = *usr_infor_head;
		ppre = NULL;

		while (pUsr_cur != NULL && pUsr_cur->usr_id <= pUsrinfor->usr_id){		//按照学号升序排列
			ppre = pUsr_cur;
			pUsr_cur = pUsr_cur->pNext_Usr_Infor;
		}
		if (ppre == NULL){
			pUsrinfor->pNext_Usr_Infor = *usr_infor_head;
			*usr_infor_head = pUsrinfor;
		}
		else
		{//中间和结尾都是这样，结尾时pcur为空
			ppre->pNext_Usr_Infor = pUsrinfor;
			pUsrinfor->pNext_Usr_Infor = pUsr_cur;
		}
	
	}
	fflush(stdin);
	printf("Enter user name:\n");
	gets(account_name);
	fflush(stdin);
	printf("Enter password:\n");
	while (j < 11) {
		account_pwd[j] = getchar();
		if (account_pwd[j] == '\b'){
			putchar('\b');
			putchar(' ');
			putchar('\b');
			j--;
		}
		else if (account_pwd[j] == 13){
			
			break;
		}
		else if (j==10)
		{
			putchar('\a');
		}
		else
		{
			j++;
			putchar('*');
		}
		//以后试试响铃'\a'	
		
	}
	account_pwd[j] = '\0';
	while (pAcc_cur != NULL && strcmp(account_name, pAcc_cur->usr_name) != 0){
		pAcc_cur = pAcc_cur->pNext_Usr_Account;
	}
	
	if ((pAcc_cur != NULL)&&(strcmp(account_name, pAcc_cur->usr_name) == 0) && strcmp(account_pwd, pAcc_cur->usr_pwd) == 0){
		//if (pAcc_cur->usr_role == 1)
		//以管理员身份进入系统
		return pAcc_cur->usr_role;
	}
	else{
		printf("\nusrname or password wrong!\n");

		return 0;//返回值还有点问题，密码不对会进入访客界面
	}
}

/*之前写在main里面
if ((fp_config = fopen(argv[1], "r")) == NULL){
sprintf(stderr, "open failed!\n");
return 1;
}
//加载账户信息
memset(line, 0, sizeof(line));
fgets(line, sizeof(line), fp_config);
line[strlen(line) - 1] = '\0';
fp_usr_account = fopen(line, "r");
if (fp_usr_account  == NULL){
fprintf(stderr, "open failed!\n");
return 1;
}
while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), fp_usr_account) != NULL){
pAccount = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
sscanf(line, "%s%s%d", pAccount->usr_name, pAccount->usr_pwd, &pAccount->usr_role);
pAccount->pNext_Usr_Account = account_head;
account_head = pAccount;
}
//加载学生信息
memset(line, 0, sizeof(line));
fgets(line, sizeof(line), fp_config);
line[strlen(line) - 1] = '\0';
fp_usr_infor = fopen(line, "r");
if (fp_usr_infor == NULL){
fprintf(stderr, "open failed!\n");
return 1;
}
while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), fp_config) != NULL){
pUsrinfor = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
sscanf(line, "%d%s%d%lf", &pUsrinfor->usr_id, pUsrinfor->usr_name, &pUsrinfor->usr_course_id, &pUsrinfor->usr_course_score);
pUsrinfor->pNext_Usr_Infor = usr_infor_head;
usr_infor_head = pUsrinfor;
}
*/
