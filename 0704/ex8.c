#include <stdio.h>

int main()
{
	int num[] = {3,6,4,5,7};
	int *pNum = num;


	printf("%d, %d \r\n",*pNum,*(pNum+1));

	int sum = 0;
	int max = -9999999;
	int min = 9999999;

	for (int i = 0; i < sizeof(num)/sizeof(int); i++)
	{
		printf("%d, ",*(pNum+i));

		sum += *(pNum+i);

		if(min > *(pNum+i))
		{
			min = *(pNum+i);

		}
		else if (max < *(pNum+i))
		{
			max = *(pNum+i);

		}
	}
	
	printf("sum : %d \r\n",sum);
	printf("min : %d \r\n",min);
	printf("max : %d \r\n",max);

	return 0;
}
