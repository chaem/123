#include <stdio.h>

int main()
{
	int num1 = 2016;
	int num2 = num1; // copy, another address
	int *ptrTemp = &num1; // pointer - none copy, take address

	printf("%d , %d \r\n",num1,*ptrTemp);

	*ptrTemp = 2015;

	printf("%d , %d , %d \r\n",num1,*ptrTemp,num2);

	return 0;
}
