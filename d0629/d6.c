#include <stdio.h>

int main()
{
	char *strTemp = "hello world";
	int index;
	printf("%s \r\n",strTemp);
	printf("%c \r\n",101);
	printf("���ڸ� �����ϼ���..");

	//printf("%c \r\n",strTemp[0]);
	scanf("%d",&index);
	
	strTemp[index] = strTemp[index] + 1; // code

	printf("%c,%d \r\n",strTemp[index],strTemp[index]);
	printf("%s \r\n",strTemp);
		
	return 0;
}
