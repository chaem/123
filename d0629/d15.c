#include <stdio.h>

int main()
{
	int num1;
	scanf("%d", &num1);
	if(num1 > 5) {
		printf("5보다 값이 큽니다. \r\n");		
	} 
	else if(num1 > 3) { //5보다 작지만 3보다는 큰 경우
		printf("3보다는 큽니다. \r\n");
	}
	else {
		printf("5보다 값이 작습니다. \r\n");
	}
	return 0;
}
