#include <stdio.h>

int main()
{
	int ary[5] = {10,20,30,40,50};
	int *ap = ary;

	printf("%d \r\n",*ap);
	printf("%d \r\n",*(ap+1));

	return 0;
}	
