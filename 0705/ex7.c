#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//char *ptr = "move position 30,20";
	char *ptr = strdup("move position 30,20");
	char *ptrTemp;
	
	ptrTemp = strtok(ptr," ");
	
	printf("%s \r\n",ptrTemp);
	printf("%s \r\n",strtok(NULL," "));
	
	ptrTemp = strtok(NULL,".");
	printf("%s \r\n",atoi(ptrTemp)+1); // change character -> number	
	
	ptrTemp = strtok(NULL,".");
	printf("%s \r\n",atoi(ptrTemp)+2); 
	
	return 0;
}
