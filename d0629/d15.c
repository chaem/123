#include <stdio.h>

int main()
{
	int num1;
	scanf("%d", &num1);
	if(num1 > 5) {
		printf("5���� ���� Ů�ϴ�. \r\n");		
	} 
	else if(num1 > 3) { //5���� ������ 3���ٴ� ū ���
		printf("3���ٴ� Ů�ϴ�. \r\n");
	}
	else {
		printf("5���� ���� �۽��ϴ�. \r\n");
	}
	return 0;
}
