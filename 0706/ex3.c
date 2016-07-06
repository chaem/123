#include <stdio.h>

void array(char **ptr_Array)
{
	for (int i=0; i<4; i++) {
		puts(ptr_Array[i]);

	}

}

int main()
{
	char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};

	array(ptr_ary);
	
	return 0;
}
