#include "sims.h"


int main(int argc, char * argv[])
{
	int digit;
	pUSR_ACCOUNT head;
	
	//create();
	//printhead();		//����Ҫ�������û�����ʼ����

	printhead1();		//�����ѡ��1--9���ֿ�ʼ


	scanf("%d", &digit);
	while  (digit < 1 || digit>9){
		printf("select a number between 1-9:");
		scanf("%d", &digit);
	}
	


	
	switch (digit){
	case 1:
		
		break;
	case 2:
		
		add();
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