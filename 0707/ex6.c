#include <stdio.h>

union _U_TEST {
	unsigned char byte[4]; // 1x4byte
	unsigned int number; // 4byte

};

//2
enum season { spring, summer, fall, winter }; // 0 1 2 3

int main()
{
	union _U_TEST test;

	test.number = 0x01020304; // 16
	
	printf("%u \r\n",test.number);

	//2
	enum season ss, ss2; // variable ss
	ss = spring;
	ss2 = summer;
	
	printf("%d, %d \r\n",ss,ss2);	

	return 0;
}
