#include "sims.h"

void show_usr_info(pUSR_INFOR pphead)
{
	system("cls");
	while (pphead != NULL){
		printf("%-5d%-10s%-3d%7.2f\n", pphead->usr_id, pphead->usr_name, pphead->usr_course_id, pphead->usr_course_score);
		pphead = pphead->pNext_Usr_Infor;
	}
	printf("\n");
}

void show_usr_account(pUSR_ACCOUNT pphead)
{
	system("cls");
	while (pphead != NULL){
		fprintf(stdout, "%-15s%-15s%3d\n", pphead->usr_name, pphead->usr_pwd, pphead->usr_role);
		pphead = pphead->pNext_Usr_Account;
		printf("\n");
	}
}


void search_usr_info_id(pUSR_INFOR *pphead, int id)
{
	pUSR_INFOR pcur;
	FILE *fp;
	pcur = *pphead;
	while (pcur != NULL){
		if (pcur->usr_id == id){
			break;
		}
		else
			pcur = pcur->pNext_Usr_Infor;
	}
	if (pcur != NULL){
		printf("%-5d%-10s%-3d%7.2f\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
	}
	else
	{
		printf("cannot find\n");
	}
}

void search_usr_info_name(pUSR_INFOR *pphead, char *name)
{
	pUSR_INFOR pcur;
	FILE *fp;
	pcur = *pphead;
	while (pcur != NULL){
		if (strcmp(name,pcur->usr_name)==0){
			break;
		}
		else
			pcur = pcur->pNext_Usr_Infor;
	}
	if (pcur != NULL){
		printf("%-5d%-10s%-3d%7.2f\n", pcur->usr_id, pcur->usr_name, pcur->usr_course_id, pcur->usr_course_score);
	}
	else
	{
		printf("cannot find\n");
	}
}

void search_usr_account_by_name(pUSR_ACCOUNT *pphead, char* name)
{
	pUSR_ACCOUNT pcur;
	pcur = *pphead;
	while (pcur != NULL){
		if (strcmp(pcur->usr_name, name) == 0)
			break;
		else
			pcur = pcur->pNext_Usr_Account;
	}
	if (pcur != NULL){
		fprintf(stdout, "%-15s%-15s%3d\n", pcur->usr_name, pcur->usr_pwd, pcur->usr_role);
	}
	else{
		fprintf(stdout, "donot exist the name\n");
	}
}


void add_usr_info(pUSR_INFOR *pphead, char *addres)
{
	pUSR_INFOR pnew = NULL;
	pUSR_INFOR pcur, ppre;
	char line[LEN];
	system("cls");
	fflush(stdin);
	printf("input: id   name   course_id   course_score\n");
	while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), stdin) != NULL){
		pnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
		sscanf(line, "%d%s%d%lf", &pnew->usr_id, pnew->usr_name, &pnew->usr_course_id, &pnew->usr_course_score);
		pcur = *pphead;
		ppre = NULL;
		//想增加判断学号是否已经存在，存在就拒接添加。
		while (pcur != NULL)
		{
			if (pcur->usr_id == pnew->usr_id)
				break;
			else
				pcur = pcur->pNext_Usr_Infor;
		}
		if (pcur == NULL){
			pcur = *pphead;
			ppre = NULL;
			while (pcur != NULL && pcur->usr_id <= pnew->usr_id){		//按照学号升序排列
				ppre = pcur;
				pcur = pcur->pNext_Usr_Infor;
			}
			if (ppre == NULL){
				pnew->pNext_Usr_Infor = *pphead;
				*pphead = pnew;
			}
			else
			{//中间和结尾都是这样，结尾时pcur为空
				ppre->pNext_Usr_Infor = pnew;
				pnew->pNext_Usr_Infor = pcur;
			}
		}
		else
		{
			fprintf(stdout, "the %d usr_infor already exist.\n",pcur->usr_id);
		}
		}

		
	
}

void add_usr_account(pUSR_ACCOUNT *pphead, char *addres)
{
	pUSR_ACCOUNT pnew = NULL;
	pUSR_ACCOUNT pcur, ppre;
	char line[LEN];
	system("cls");
	fflush(stdin);
	printf("input: usr_name\tusr_pwd\tusr_role\n");
	while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), stdin) != NULL){
		pnew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
		sscanf(line, "%s%s%d", pnew->usr_name, pnew->usr_pwd, &pnew->usr_role);
		pnew->pNext_Usr_Account = *pphead;
		*pphead = pnew;
	}
}


void save_usr_account(pUSR_ACCOUNT *pphead, char *addres)
{
	pUSR_ACCOUNT pcur;
	FILE *fp_config, *fp_usr_account;
	char line[LEN];
	pcur = *pphead;
	if ((fp_config = fopen(addres, "r")) == NULL){
		printf("file cannot open fp_config\n");
		return;
	}
	//已知usr_account在第一行,不知道怎么判断?
	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), fp_config);
	line[strlen(line)-1] = '\0';
	if ((fp_usr_account = fopen(line, "w")) == NULL){
		printf("file cannot open fp_usr_account\n");
		return;
	}
	fclose(fp_config);
	while (pcur != NULL){
		if (fprintf(fp_usr_account, "%-10s%-10s%-5d\n", pcur->usr_name,pcur->usr_pwd,pcur->usr_role) == EOF)
			printf("write error\n");
		pcur = pcur->pNext_Usr_Account;
	}
	fclose(fp_usr_account);
}

void save_usr_info(pUSR_INFOR *pphead, char *addres)
{
	pUSR_INFOR pcur;
	FILE *fp_config, *fp_usr_infor;
	char line[LEN];
	pcur = *pphead;
	if ((fp_config = fopen(addres, "r")) == NULL){
		printf("file cannot open fp_config\n");
		return;
	}
	//已知usr_info在第二行所以采取读两次来调用，没有想到怎么用数组或者链表?
	memset(line, 0, sizeof(line));
	//第一行有\n，第二行没有\n
	fgets(line, sizeof(line), fp_config);
	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), fp_config);
	if ((fp_usr_infor = fopen(line, "w")) == NULL){
		printf("file cannot open fp_usr_infor\n");
		return;
	}
	fclose(fp_config);
	while (pcur != NULL){
		if (fprintf(fp_usr_infor, "%-5d%-10s%-5d%8.2f\n", pcur->usr_id,pcur->usr_name,pcur->usr_course_id,pcur->usr_course_score) == EOF)
			printf("write error\n");
		pcur = pcur->pNext_Usr_Infor;
	}
	fclose(fp_usr_infor);
}


void delet_usr_info_by_id(pUSR_INFOR *pphead, int id)
{
	pUSR_INFOR pcur, ppre;
	FILE *fp;
	pcur = *pphead;
	ppre = NULL;
	while (pcur != NULL){
		if (pcur->usr_id == id){
			break;
		}
		else{
			ppre = pcur;
			pcur = pcur->pNext_Usr_Infor;
		}
			
	}
	if (pcur != NULL){
		if (ppre == NULL){
			//删除第一个结点
			*pphead = pcur->pNext_Usr_Infor;
		}
		else{
			ppre->pNext_Usr_Infor = pcur->pNext_Usr_Infor;
			
		}
		free(pcur);
		pcur = NULL;
	}
	else
	{
		printf("donot exist in the file.\n");
	}
	if (*pphead == NULL){
		free(*pphead);
		*pphead = NULL;
	}
}

void delet_usr_info_by_name(pUSR_INFOR *pphead, char *name)
{
	pUSR_INFOR pcur, ppre;
	FILE *fp;
	pcur = *pphead;
	ppre = NULL;
	while (pcur != NULL){
		if (strcmp(pcur->usr_name,name)==0){
			break;
		}
		else{
			ppre = pcur;
			pcur = pcur->pNext_Usr_Infor;
		}

	}
	if (pcur != NULL){
		if (ppre == NULL){
			//删除第一个结点
			*pphead = pcur->pNext_Usr_Infor;
		}
		else{
			ppre->pNext_Usr_Infor = pcur->pNext_Usr_Infor;

		}
		free(pcur);
		pcur = NULL;
	}
	else
	{
		printf("donot exist in the file.\n");
	}
	if (*pphead == NULL){
		free(*pphead);
		*pphead = NULL;
	}
}

//账户信息不能全部删除，需要加判断？？？
void delet_usr_account_by_name(pUSR_ACCOUNT *pphead, char* name)
{
	pUSR_ACCOUNT pcur, ppre;
	char line[LEN];
	pcur = *pphead;
	ppre = NULL;
	while (pcur != NULL &&  strcmp(pcur->usr_name, name) != 0){
		ppre = pcur;
		pcur = pcur->pNext_Usr_Account;
	}
	if (pcur != NULL){
		ppre->pNext_Usr_Account = pcur->pNext_Usr_Account;
		fprintf(stdout, "delete ok.\n");
	}
	else
	{
		fprintf(stdout, "delete error, donot exit\n");
	}

}


void updat_usr_infor_by_id(pUSR_INFOR *pphead, int id)
{
	pUSR_INFOR pcur;
	char line[LEN];
	pcur = *pphead;
	while (pcur != NULL){
		if (pcur->usr_id == id){
			break;
		}
		else
			pcur = pcur->pNext_Usr_Infor;
	}
	if (pcur != NULL){
		//只能修改后面三项内容
		fflush(stdin);
		memset(line, 0, sizeof(line));
		printf("updat NO.%d new infor\nname\tcouse_id\tcours_score:\n ", pcur->usr_id);
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%s%d%lf", pcur->usr_name, &pcur->usr_course_id, &pcur->usr_course_score);

	}
	else
	{
		printf("cannot find the id_infor\n");
	}
}

void update_usr_account_by_name(pUSR_ACCOUNT *pphead, char* name)
{
	pUSR_ACCOUNT pcur;
	char line[LEN];
	pcur = *pphead;
	while (pcur != NULL &&  strcmp(pcur->usr_name, name) != 0){
		pcur = pcur->pNext_Usr_Account;
	}
	if (pcur != NULL){
		memset(line, 0, sizeof(line));
		fflush(stdin);
		fprintf(stdout, "usr_pwd\t\tusr_role:\n");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%s%d", pcur->usr_pwd, &pcur->usr_role);
	}
	else
	{
		fprintf(stdout, "updata usr_account error\n");
	}

}


