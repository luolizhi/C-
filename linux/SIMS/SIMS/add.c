#include "sims.h"
void add(void)
{
	USR_INFOR  stu[N];
	int i = 1;
	char line[128];
	char ch;
	system("cls");
	printf("\t\t2. add		student information\n\n");
	do{
		fflush(stdin);
		printf("id  name  coure_id  couse_score:\n");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d%s%d%lf", &stu[i].usr_id, stu[i].usr_name, &stu[i].usr_course_id, &stu[i].usr_course_score);

		/*
		//����ѧ��
		printf("input student id:");
		scanf("%d", &stu[i].usr_id);
		getchar();
		//��������
		printf("input student name:");
		fgets(stu[i].usr_name, 20, stdin);
		//getchar();
		//����γ̺�
		printf("input student_course_id:");
		scanf("%d", &stu[i].usr_course_id);
		getchar();
		//����γ̷���
		printf("input usr_course_score:");
		scanf("ld", &stu[i].usr_course_score);
		*/

		stu[i].pNext_Usr_Infor = &stu[++i];
		fflush(stdin);
		printf("\ndo you want contine y/n?");
		ch = getchar();
	} while (ch  == 'y' || ch  == 'Y');
	save(stu, i-1);

}