#include <stdio.h>

int main()
{
	int num[] = {3,7,15,6,8};

	printf("%d \r\n",sizeof(num)/sizeof(int));
	//배열 크기 int 4byte x 6 = 24

	int sum = 0;
	int max = -99999999;
	int min = 99999999;
	
	for (int i = 0; i < sizeof(num)/sizeof(int); i++)
	{
		//sum = sum + num[i];
		sum += num[i];

		if (max < num[i])
		{
			max = num[i];

		}
		else if (min > num[i])
		{
			min = num[i];

		}

	}

	printf("sum : %d \r\n",sum);
	printf("max : %d \r\n",max);
	printf("min : %d \r\n",min);

	return 0;

}
