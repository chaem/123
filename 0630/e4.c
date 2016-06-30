#include <stdio.h>

int main()
{
	int i=0;
	int d=10;
	while (i <= 10)
	{
		printf("increase = %d \r\n",i);
		i+=1; //i++;
	}

	while (d >= 0)
	{
		printf("decrease = %d \r\n",d);
		d--; //d-=1;
	}
	return 0;
}
