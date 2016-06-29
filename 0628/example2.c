#include <stdio.h>

int main()
{
	int hitpoint,bonus_hit;
	hitpoint = 100;
	bonus_hit = 20;

	printf("total status = %d\r\n",hitpoint + bonus_hit);
	printf("hello, C language\r\n");
	
	/* 10 문자열 출력 */
	printf("10");

	/* 정수값을 문자열로 변환, 변환 문자열 정수값을 넣는다 */
	printf("%d", 10);
	printf("%d %d", 10, 20);
	printf("%d", 10+30);

	return 0;
}

