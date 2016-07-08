#include <stdio.h>
#include "ex2_2.h"

extern int nCount; // reset X // safy compile

int main()
{
	nCount = 10;
	foo();
	foo();

	return 0;
}
