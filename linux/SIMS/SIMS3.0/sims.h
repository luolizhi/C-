#ifndef __FUNC_C__
#define __FUNC_C__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 128
#define M 100   //账户最多人数
#define N 1000	//学生最多人数
#define USR_NAME_LEN 20
#define USR_PWD_LEN  20
//#include<curses.h>

typedef int USR_ROLE;

//账号信息
typedef struct usr_account_tag
{
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	USR_ROLE  usr_role;							//管理员设置为1，其它设置为0
	struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;


//学生信息
typedef struct usr_infor_tag
{
	int usr_id;								//学号
	char usr_name[USR_NAME_LEN];			//姓名
	int usr_course_id;						//课程号
	double usr_course_score;				//课程分数
	struct usr_infor_tag *pNext_Usr_Infor;	//下一个学生信息

}USR_INFOR, *pUSR_INFOR;


USR_ROLE system_init(pUSR_ACCOUNT *account_head, pUSR_INFOR *usr_infor_head, char *addres);

USR_ROLE system_menu(USR_ROLE type);
USR_ROLE  search_menu(USR_ROLE type);
void usr_infor_delete_menu(void);
void account_search_menu(void);
void show_usr_info(pUSR_INFOR pphead);
void show_usr_account(pUSR_ACCOUNT pphead);

void search_usr_info_id(pUSR_INFOR *pphead, int id);
void search_usr_info_name(pUSR_INFOR *pphead, char *name);

void save_usr_info(pUSR_INFOR *pphead, char *addres);
void add_usr_info(pUSR_INFOR *pphead, char *addres);
void delet_usr_info_by_id(pUSR_INFOR *pphead, int id);
void delet_usr_info_by_name(pUSR_INFOR *pphead, char *name);
void delet_usr_account_by_name(pUSR_ACCOUNT *pphead, char* name);
void updat_usr_infor_by_id(pUSR_INFOR *pphead, int id);
void update_usr_account_by_name(pUSR_ACCOUNT *pphead, char* name);
void add_usr_account(pUSR_ACCOUNT *pphead, char *addres);
void save_usr_account(pUSR_ACCOUNT *pphead, char *addres);
void search_usr_account_by_name(pUSR_ACCOUNT *pphead, char* name);



#endif
