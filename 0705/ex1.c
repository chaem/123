#include <stdio.h>

int main()
{
	int ary[5] = {1,2,3,4,5};
	int ary2[5];
	
	// int *pAry = ary;
	int *pAry;
	pAry = ary; // (O)  // pointer variable <- value
	
	printf("%d %d \r\n",*(pAry+1),*(ary+1));
	printf("%d %d \r\n",pAry[1],ary[1]);

	//ary2 = ary; (X)  // pointer, array <-X- value

	return 0;	
}
