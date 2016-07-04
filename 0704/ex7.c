#include <stdio.h>

int main()
{
	int num[10] = {4,5,3,8,6};

	printf("%d \r\n",sizeof(num));
	//4,5,3,8,6,0,0,0,0,0

	printf("%d \r\n",sizeof(int));
	//int [0],[1],[2],[3],[4]
	
	for(int i = 0; i < sizeof(num)/sizeof(int); i++)
	{
		printf("%d,",num[i]);

	}
			
	return 0;

}
