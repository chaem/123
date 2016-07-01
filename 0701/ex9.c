#include <stdio.h>

int main()
{
	int test1[] = {1,2,3,4,5};
	int *ptrTemp1; //(int=4byte) pointer
	char *ptrTemp2; //(char=1byte) pointer

	ptrTemp1 = test1; //copied test1 value / new address
	ptrTemp2 = (char *)test1; //change shape

	printf("%d %d \r\n",ptrTemp1[0],ptrTemp1[1]);
	printf("%d %d \r\n",ptrTemp2[0],ptrTemp2[1]);
	printf("\r\n");
	
	printf("%d %d \r\n",*ptrTemp1,ptrTemp1[1]);
	printf("%d %d \r\n",*ptrTemp2,*ptrTemp2);
	printf("%d %d \r\n",*ptrTemp2,*(ptrTemp2+4));
	printf("\r\n");

	printf("%x %x \r\n",*ptrTemp1,ptrTemp1[1]);
	printf("%x %x \r\n",*ptrTemp2,*ptrTemp2);
	printf("%x %x \r\n",*ptrTemp2,*(ptrTemp2+4));
	printf("\r\n");


	printf("%x %x \r\n",ptrTemp1,ptrTemp1+1); //ptrTemp1=4, +1=5
	printf("%x %x \r\n",ptrTemp2,ptrTemp2+1); //"2"
	printf("%x %x \r\n",ptrTemp2,ptrTemp2+4); //ptrTemp2=1, +4=5


	return 0;
}
