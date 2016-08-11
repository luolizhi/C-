#ifndef __FUNC_C__
#define __FUNC_C__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 128
#define M 100   //�˻��������
#define N 1000	//ѧ���������
#define USR_NAME_LEN 20
#define USR_PWD_LEN  20

typedef char USR_ROLE;

//�˺���Ϣ
typedef struct usr_account_tag
{
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	USR_ROLE  usr_role;							//����Ա����Ϊ1����������Ϊ0
	struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;


//ѧ����Ϣ
typedef struct usr_infor_tag
{
	int usr_id;								//ѧ��
	char usr_name[USR_NAME_LEN];			//����
	int usr_course_id;						//�γ̺�
	double usr_course_score;				//�γ̷���
	struct usr_infor_tag *pNext_Usr_Infor;	//��һ��ѧ����Ϣ

}USR_INFOR, *pUSR_INFOR;



void printhead(void);
void add_usr_info(pUSR_INFOR *pphead);
void save_usr_info(pUSR_INFOR *pphead);
void show_usr_info(pUSR_INFOR pphead);
void search_usr_info(pUSR_INFOR *pphead, int value);
void printhead_search(void);



#endif