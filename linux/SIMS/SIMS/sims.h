#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void printhead1(void);
void printhead2(void);
void add(void);
int  enter(pUSR_ACCOUNT usr);	//��¼
void account(struct usr_account_tag *head);//�˻���Ϣ
void create(void);		//�����˻�
void save(pUSR_INFOR arr, int len);//����ѧ����Ϣ

/*
int security(); 
void encrypt(char *p); 
void decrypt(char *p); 
void read(); 
void find(); 
void list(); 
void modify(); 
void add(); 
void del(); 
void clear(); 
void save(); 
void help(); 
void quit();


*/
//pUSR_INFOR update_usr_infor(pUSR_INFOR pUsr_Infor_List, SEARCH_ID search_id);