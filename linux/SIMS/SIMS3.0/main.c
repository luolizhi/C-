#include "sims.h"

int main(int argc, char *argv[])
{

		pUSR_INFOR usr_infor_head = NULL;
		pUSR_ACCOUNT account_head = NULL;
		char *paddres;		//传递配置文件地址
		int digit;
		int s_digit, d_digit;
		int usr_id, delet_id;
		char usr_name[LEN] = "";
		char usr_account_name[LEN] = "";
		USR_ROLE  type, s_type;	//登陆者身份标示
		paddres = (char *)calloc(1, sizeof(char));
		paddres = argv[1];
		//加载初始账户密码和学生信息
		
		type = system_init(&account_head, &usr_infor_head, paddres);
		while (1){
			system("cls");
			s_type = system_menu(type);

			//以管理员身份登录
			if (s_type == 1){
				
				fflush(stdin);
				scanf("%d", &digit);
				while (digit < 1 || digit > 9) {
					fflush(stdin);
					//system("cls");
					scanf("%d", &digit);
				}
				switch (digit){
				case 1:
					search_menu(s_type);
					scanf("%d", &s_digit);
					while (s_digit < 0 || s_digit > 3) {
						fflush(stdin);
						//system("cls");
						scanf("%d", &s_digit);
					}
					switch (s_digit)
					{
					case 0:
						//show all usr_infor
						show_usr_info(usr_infor_head);
						system("pause");
						break;
					case 1:
						//search by id
						fflush(stdout);
						system("cls");
						fflush(stdin);
						printf("input usr_id:\n");
						scanf("%d", &usr_id);
						search_usr_info_id(&usr_infor_head, usr_id);
						break;
					case 2:
						//search  by name
						system("cls");
						fflush(stdin);
						printf("input usr_name:\n");
						scanf("%s", usr_name);
						search_usr_info_name(&usr_infor_head, usr_name);
						break;
					case 3:
						;
						//s_type = system_menu(type);
					default:
						break;
					}
					break;

				case 2:
					//add
					add_usr_info(&usr_infor_head, argv[1]);
					save_usr_info(&usr_infor_head, argv[1]);
					system("pause");
					break;
				case 3:
					//update by id
					fflush(stdout);
					system("cls");
					fflush(stdin);
					printf("input usr_id:\n");
					scanf("%d", &usr_id);
					updat_usr_infor_by_id(&usr_infor_head, usr_id);
					save_usr_info(&usr_infor_head, argv[1]);
					system("pause");
					break;
				case 4:
					
					usr_infor_delete_menu();
					scanf("%d", &d_digit);
					//delet by id
					if (d_digit == 1){
						system("cls");
						fflush(stdin);
						printf("input delet_usr_id:\n");
						scanf("%d", &delet_id);
						delet_usr_info_by_id(&usr_infor_head, delet_id);
						save_usr_info(&usr_infor_head, argv[1]);
					}
					//delet by name
					else if (d_digit == 2){
						system("cls");
						fflush(stdin);
						printf("input delet_usr_name:\n");
						scanf("%s", usr_name);
						delet_usr_info_by_name(&usr_infor_head, usr_name);
						save_usr_info(&usr_infor_head, argv[1]);
					}
		
					system("pause");
					break;
				case 5:
					//add user account
					add_usr_account(&account_head, argv[1]);
					//save
					save_usr_account(&account_head, argv[1]);
					break;
				case 6:
					//update usr_account
					system("cls");
					fflush(stdin);
					printf("input usr_account_name:\n");
					scanf("%s", usr_account_name);
					update_usr_account_by_name(&account_head, usr_account_name);
					save_usr_account(&account_head, argv[1]);
					break;
				case 7:
					//delet usr_account_by_name
					system("cls");
					fflush(stdin);
					printf("input usr_account_name:\n");
					scanf("%s", usr_account_name);
					delet_usr_account_by_name(&account_head, usr_account_name);
					save_usr_account(&account_head, argv[1]);
					break;
				case 8:
					//search usr_account
					account_search_menu();
					scanf("%d", &s_digit);
					while (s_digit < 0 || s_digit > 3) {
						fflush(stdin);
						//system("cls");
						scanf("%d", &s_digit);
					}

					if (s_digit == 0){
						//show all account
						show_usr_account(account_head);
					}
					else if (s_digit == 1){
						//search by name
						system("cls");
						fflush(stdin);
						printf("input usr_name:\n");
						scanf("%s", usr_account_name);
						search_usr_account_by_name(&account_head, usr_account_name);
					}
					//else
					//	exit(0);
					break;
				case 9:
					exit(0);
					break;
				default:
					printf("select a digit between 1--9:");
				}
			}
			//以访客身份登录
			else if (s_type == 2)
			{
				fflush(stdin);
				scanf("%d", &digit);
				while (digit != 1 && digit != 9) {
					fflush(stdin);
					//system("cls");
					scanf("%d", &digit);
				}

				if (digit == 1){
					search_menu(s_type);
					scanf("%d", &s_digit);
					while (s_digit < 0 || s_digit > 3) {
						fflush(stdin);
						scanf("%d", &s_digit);
					}
					if (s_digit == 1)
					{
						//search by id
						fflush(stdout);
						system("cls");
						fflush(stdin);
						printf("input usr_id:\n");
						scanf("%d", &usr_id);
						search_usr_info_id(&usr_infor_head, usr_id);
					}
					else if (s_digit == 2){
						//search by name
						system("cls");
						fflush(stdin);
						printf("input usr_name:\n");
						scanf("%s", usr_name);
						search_usr_info_name(&usr_infor_head, usr_name);
						//system("pause");
					}
					else    //(s_digit == 3)  退出
						;
				}
				else //if (digit == 9)
				{
					//break;
				}		
			}
		}//while(1)


	system("pause");
	return 0;
}