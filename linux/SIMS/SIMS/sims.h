#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100   //账户最多人数
#define N 1000	//学生最多人数
#define USR_NAME_LEN 20
#define USR_PWD_LEN  20

typedef char USR_ROLE;

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




void printhead(void);
void printhead1(void);
void printhead2(void);
void add(void);
int  enter(pUSR_ACCOUNT usr);	//登录
void account(struct usr_account_tag *head);//账户信息
void create(void);		//创建账户
void save(pUSR_INFOR arr, int len);//保存学生信息

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