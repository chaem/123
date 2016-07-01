#include <stdio.h>

int sum(int a,int b)
{
	int res; //변수에 a+b값을 넣는다
	res = a+b;

	return res;
}

int main()
{
	printf("%d \r\n",sum(2,3));

	return 0;
}
