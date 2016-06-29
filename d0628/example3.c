#include <stdio.h>

int main()
{
	/* »ö»ó */
	printf("hello \r\n");
	printf("\x1b[31m");
	printf("hello \r\n");
	printf("\x1b[1;31m");
	printf("hello vt100\r\n");
	
	printf("\x1b[1;31m");
	printf("l");
	printf("\x1b[1;32m");
	printf("e");
	printf("\x1b[1;33m");
	printf("e");
	printf("\x1b[1;34m");
	printf("c");
	printf("\x1b[1;35m");
	printf("h");
	printf("\x1b[1;36m");
	printf("a");
	printf("\x1b[1;37m");
	printf("e");
	printf("\x1b[1;31m");
	printf("m");
	printf("\x1b[1;32m");
	printf("i");
	printf("\x1b[1;33m");
	printf("n");

	return 0;
	
}
