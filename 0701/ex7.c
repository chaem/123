#include <stdio.h>

//testAr[0] = 100
//testAr[1] = 101
//testAr[2] = 102
//testAr[3] = 103
//testAr[4] = 104
//testAr[5] = \0 (null)
int testAr[5] = {100,101,102,103,104};

char testAr2[5] = {100,101,201,103,104};

int main()
{
	printf("%d \r\n",testAr[0]);

	int *pTemp = testAr; //pointer
	printf("%d \r\n",pTemp[0]);
	printf("%d \r\n",pTemp[3]);
	printf("%d \r\n",pTemp[5]);

	printf("%d \r\n",pTemp); //memory (physical address)
	printf("%d , %d , %d \r\n",pTemp,pTemp+1,pTemp+2); //int=4byte
	printf("%d , %d , %d \r\n",*pTemp,*(pTemp+1),*(pTemp+2)); //first () / value

	char *pTemp2 = testAr2;
	printf("%d \r\n",testAr2[2]);
	printf("%d , %d , %d \r\n",pTemp2,pTemp2+1,pTemp2+2); //char=1byte

	return 0;
}
