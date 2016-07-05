#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/*
	 *stack2
	 *stack1
	 */
	int a; // stack1
	a = 1;
	{
		int a; // stack2
		a = 3;
		printf("%d \r\n",a);
	}
	printf("%d \r\n",a);

	return 0;
}
