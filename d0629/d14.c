#include <stdio.h>

int main()
{
	int res = 1 > 2; //result = wrong -> 0
	printf("%d \r\n",res);
	
	res = 1 < 2; //result = right -> 1
	printf("%d \r\n",res);
	
	res = (1 == 2); //result = 1 != 2 -> 0 (wrong)
	printf("1==2 ? %d \r\n",res);

	res = (1 != 2); //result = 1 != 2 -> 1 (right)
	printf("1!=2 ? %d \r\n",res);

	res = (1 <= 2); //result = 1(right)
	printf("1<=2 ? %d \r\n",res);
	
	//&& -> and
	printf("%d,%d,%d,%d \r\n",(1&&1),(1&&0),(0&&1),(0&&0));
	printf("%d,%d,%d,%d \r\n",(1||1),(1||0),(0||1),(0||0));
	printf("%d \r\n",(1<2)); //true = 1
	printf("%d \r\n",!(1<2)); //lie = 0
	return 0;
}
