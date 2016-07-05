#include <stdio.h>

int main()
{
	char *ptrArray[5] = {
		"windows",
		"Unix",
		"Linux",
		"java",
		"android"
	};

	for (int i=0; i<5; i++) {
		puts(ptrArray[i]);
	
	}
	
	for (int i=0; i<5; i++) {
		putchar(ptrArray[i][0]); //세로

	}
	puts("");

	for (int i=0; i<5; i++) {
		putchar(ptrArray[0][i]); //가로

	}

	return 0;
}
