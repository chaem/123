#include <stdio.h>

int main()
{
	double a = 1.3;
	double b = 1.7;
	double change;
	
	double *pa,*pb;

	printf("�ٲٱ� ��  a,b �� : %f, %f \r\n",a,b);

	/*
	change = a;
	a = b;
	b = change;
	*/
	
	pa = &a;
	pb = &b;

	change = *pa;
	*pa = *pb;
	*pb = change;

	printf("�ٲ� �� a,b �� : %f, %f \r\n",a,b);

}
