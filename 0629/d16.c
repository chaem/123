#include <stdio.h>

int main()
{
	//5~9
	int num1;
	scanf("%d",&num1);

	if(num1 <=9 && num1 >= 5) {
		printf("Right! \r\n");
	} else {
	printf("games over \r\n");
	}
	if(num1 == 100) {
		printf("입력한 숫자 : %d\r\n",num1);
	}
	return 0;
}
