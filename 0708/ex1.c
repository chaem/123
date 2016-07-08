#include <stdio.h>

//#define pi 3.14 //macro // previous compile
const double pi; // start time
//const double pi = 3.14;

int main() 
{
	//1
	double pi = 1.14;
	pi = 5.14;

	//2
	int a = 10, b = 20;
	
	//const int *ap = &a;
	const int *ap;
	const int *ab;
	ap = &a;
	ab = &b;

	b = 25;

	//1	
	printf("%.2lf \r\n",pi); // 2lf (. second line show number)	

	//2
	printf("%d, %d \r\n",*ap,*ab);
	return 0;
}
