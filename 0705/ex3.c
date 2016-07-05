#include <stdio.h>

int main()
{
	char aStr[] = "world";
	char *pStr = "hello";

	printf("%s %s \r\n",aStr,pStr)
	pStr = aStr;

	printf("%s \r\n",pStr);

	return 0;
}
