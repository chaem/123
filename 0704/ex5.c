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

	printf("�ٲٱ� �� �� : %d, %d \r\n",a,b);

	exchange(&a, &b); //�Լ� ȣ��
	printf("�ٲ� �� �� : %d, %d \r\n",a,b);

	return 0;
}
