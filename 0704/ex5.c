#include <stdio.h>

void exchange(int *pa, int *pb)
{
	/*
	*pa = 20;
	*pb = 10;
	*/
	int c;

	c = *pb;
	*pb = *pa;
	*pa = c;
}

int main()
{
	int a = 10, b = 20;

	printf("바꾸기 전 값 : %d, %d \r\n",a,b);

	exchange(&a, &b); //함수 호출
	printf("바뀐 후 값 : %d, %d \r\n",a,b);

	return 0;
}
