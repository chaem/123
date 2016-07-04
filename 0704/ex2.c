#include <stdio.h>

int main()
{
	double a = 1.3;
	double b = 1.7;
	double change;
	
	double *pa,*pb;

	printf("바꾸기 전  a,b 값 : %f, %f \r\n",a,b);

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

	printf("바꾼 후 a,b 값 : %f, %f \r\n",a,b);

}
