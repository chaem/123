#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* static memory assignment
	int a;
	int *ip;
	ip = &a;

	*ip = 10;

	printf("%d \r\n",*ip);
	*/

	// dynamic memory assignment
	int a;
	int *ip;

	ip = (int *)malloc(4);
	
	*ip = 10;
	
	printf("%d \r\n",*ip);

	free(ip); //return assignment

	return 0;
}
