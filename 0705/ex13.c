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
		putchar(ptrArray[i][0]); //����

	}
	puts("");

	for (int i=0; i<5; i++) {
		putchar(ptrArray[0][i]); //����

	}

	return 0;
}
