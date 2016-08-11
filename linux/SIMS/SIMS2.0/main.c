#include "func.h"

int main(int argc, char *argv[])
{
	pUSR_INFOR phead = NULL;
	
	int digit;
	int number;
	int key;

	printhead();




	scanf("%d", &digit);
	while (digit < 1 || digit>9) {
		fflush(stdin);
		system("cls");
		printhead();
		scanf("%d", &digit);
	}
	switch (digit){
	case 1:



		printhead_search();


		scanf("%d", &number);
		if (number == 1){

		}
		else if (number == 2){
			printf("id\n");
			scanf("%d", &key);
			search_usr_info(&phead, key);
		}

		//search_usr_info(phead,value);
		break;
	case 2:
		add_usr_info(&phead);
		//show_usr_info(phead);//≤‚ ‘
		save_usr_info(&phead);
		//show_usr_info(phead);
		break;
	case 3:

		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	default:
		printf("select a digit between 1--9:");
	}



	system("pause");
	return 0;
}