#include <stdio.h>

int main()
{
	int hitpoint,bonus_hit;
	hitpoint = 100;
	bonus_hit = 20;

	printf("total status = %d\r\n",hitpoint + bonus_hit);
	printf("hello, C language\r\n");
	
	/* 10 ���ڿ� ��� */
	printf("10");

	/* �������� ���ڿ��� ��ȯ, ��ȯ ���ڿ� �������� �ִ´� */
	printf("%d", 10);
	printf("%d %d", 10, 20);
	printf("%d", 10+30);

	return 0;
}

