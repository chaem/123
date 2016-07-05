#include <stdio.h>
#include <string.h>

int main()
{
	char *pStr = "Delicious! apple. ";
	char strTemp[128]; // none reset array

	strcpy(strTemp,pStr); // copied pStr -> strTemp

	// different storage
	strTemp[0] = 'R'; // modified strTemp / not modified pStr
	printf("original %s \r\n",pStr);
	printf("%s copied \r\n",strTemp);

	printf("length : %d \r\n",strlen(strTemp));

	int cmp = strcmp("hello","rello");

	printf("%d \r\n",cmp);

	
	char *pStr2 = "how much this one?";

	printf("%s \r\n",strcat(strTemp,pStr2));
	return 0;
}
