#include <stdio.h>
#include <string.h>

int main()
{
	char *pStrCmd = "move position 123,56";

	char *ptr = strstr(pStrCmd,"position");

	printf("%s \r\n",ptr);


	//
	char pStrTemp[128];

	strncpy(pStrTemp,pStrCmd,4); //ncpy

	printf("%s \r\n",pStrTemp);


	//
	char *pStrClone;

	pStrClone = strdup(pStrCmd);
	pstrClone[0] = 'a';

	printf("%s \r\n",pStrClone);
	printf("%s \r\n",pStrCmd);

	return 0;
}
