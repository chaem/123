#include <stdio.h>

int main()
{
	char str[80] = "dream~";

	printf("%s \r\n",str);

	int nCount = 0;
	//while (str[++nCount] != 0) = 5 (null X)
	while (str[nCount++] != 0) { // =6 (null O)
		
	}

	printf("%d",nCount);

	return 0;
}
