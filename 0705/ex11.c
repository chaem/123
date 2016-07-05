#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ex_sum = 0; //static memory

void test()
{
	//int sum = 0; /stack
	static int sum = 0; //static memory
	sum++;
	printf("%d \r\n",sum);

	ex_sum++;
}

extern int test_num;

int main()
{
	test();
	test();
	
	// printf("%d",sum);
	printf("%d",ex_sum);
	
	printf("%d",test_num);	
	return 0;
	//stack - 1, 1
	//static - 1, 2
}
