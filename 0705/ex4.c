#include <stdio.h>
#include <stdlib.h>

int main()
{
	char strTemp[64];
	char strTemp2[64];

	scanf("%s %s",strTemp,strTemp2);

	printf("%s %s \r\n",strTemp,strTemp2);

/*
	int nCount = 0;
	for (int i=0; strTemp[i] !=0; i++) {
		if (strTemp[i] == 'l') {
			nCount++;

		}

	}
	system("clear");
	printf("%d \r\n",nCount);
*/
	int nSize1, nSize2;
	int i;
	for (i=0; strTemp[i] != 0x00; i++);
	nSize1 = i;
	for (i=0; strTemp2[i] != 0x00; i++);
	nSize2 = i;

	printf("%d, %d \r\n",nSize1,nSize2);

	if (nSize1 != nSize2) {
		printf("different \r\n");

	} else {
		int match = 1;
		for (i=0; i<nSize1; i++) {
			if(strTemp[i] != strTemp2[i]) {
				match = 0;
				break;

			}
		}
		if (match) {
			printf("same \r\n");

		} else {
			printf("dirfferent \r\n");

		}

	}


	return 0;
}
