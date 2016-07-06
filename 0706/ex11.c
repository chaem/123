#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char temp[128];
	char *str[3];

	for (int i=0; i<3; i++) {
		gets(temp);
		int length = strlen(temp); // length?

		str[i] = (char *)malloc(length * sizeof(char) + 1); // +1 = null

		strcpy(str[i],temp); // copied - original
	}

	puts("==================================");
	for (int i=0; i<3; i++) {
		puts(str[i]);

	}
	
	for (int i=0; i<3; i++) {
		free(str[i]);	

	}

	return 0;
}
