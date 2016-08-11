#include "func.h"

void add_usr_info(pUSR_INFOR *pphead)
{
	pUSR_INFOR pnew = NULL;
	pUSR_INFOR pcur, ppre;
	char line[LEN];
	system("cls");
	fflush(stdin);
	printf("input: id   name   course_id   course_score\n");
	while (memset(line, 0, sizeof(line)), fgets(line, sizeof(line), stdin) != NULL){
		pnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
		sscanf(line, "%d%s%d%lf", &pnew->usr_id,pnew->usr_name,&pnew->usr_course_id,&pnew->usr_course_score);
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
	//save_usr_info(&pphead);
	
}

void save_usr_info(pUSR_INFOR *pphead)
{
	pUSR_INFOR pcur;
	FILE *fp;
	pcur = *pphead;
	if ((fp = fopen("d://Usr_infor.txt", "ab")) == NULL){
		printf("file cannot open\n");
		return;
	}
	while (pcur != NULL){
		if (fwrite(pphead, sizeof(USR_INFOR), 1, fp) != 1)
			printf("write error\n");
		pcur = pcur->pNext_Usr_Infor;
	}
	fclose(fp);
}

void search_usr_info(pUSR_INFOR *pphead, int value)
{
	pUSR_INFOR pcur;
	FILE *fp;
	pcur = *pphead;
	fp = fopen("d://Usr_infor.txt", "rb");
	while (pcur != NULL) {
		if (fread(pcur, sizeof(USR_INFOR), 1, fp) != 1){
			printf("read error\n");
		}
		if (pcur->usr_id == value){
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



void show_usr_info(pUSR_INFOR pphead)
{
	while (pphead != NULL){
		printf("%-5d%-10s%-3d%7.2f\n", pphead->usr_id, pphead->usr_name, pphead->usr_course_id, pphead->usr_course_score);
		pphead = pphead->pNext_Usr_Infor;
	}
}