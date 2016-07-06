#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ip;
	int nCount = 0;
	int sum = 0;

	puts("input amount of data : ");
	scanf("%d",&nCount);

	ip = (int *)malloc(sizeof(int) * nCount);

	for (int i=0; i<nCount; i++) {
		puts("Please enter data");
		//scanf("%d",ip+i);
		scanf("%d",&(ip[i]));
	}

	for (int i=0; i<nCount; i++) {
		sum += ip[i];

	}

	printf("%d \r\n",sum);

	free(ip); // return assignment

	return 0;
}
