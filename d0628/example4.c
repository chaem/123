#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("clear");
	printf("\x1b[1;0f");
	printf("&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&");
	/* ȭ�� ���� �� */

	printf("\x1b[1;20f");
	printf("-");

	printf("\x1b[2;20f");
	printf("-");

	/* ȭ�� ������ */

	printf("\x1b[3;4f");
	printf("hello");

	printf("\x1b[3;20f");
	printf("-");

	printf("\x1b[4;20f");
	printf("-");

	printf("\x1b[6;8f");
	printf("welcome");

	printf("\x1b[9:12f");
	printf("to my world");

	printf("\x1b[20;0f");
	printf("&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&=&");

	return 0;
}
