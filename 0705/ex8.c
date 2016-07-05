#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char cmd[] = "add 100,30";

	int a,b;
	char *ptCmd;

	ptCmd = strtok(cmd," ");
	
	a = atoi(strtok(NULL,"."));
	b = atoi(strtok(NULL,"."));

	printf("result : %d \r\n",a+b);


	return 0;
}
