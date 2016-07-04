#include <stdio.h>

int main()
{
	char word[50] = "Hi~ world";

/*
	word[0] = 'L';
	word[1] = 'O';
	word[2] = 'V';
	word[3] = 'E';
	word[4] = 0x00; // 0x00 = null(0)
	printf("%s \r\n",word);

	int i = 0;
	while (word[i] != 0x00)
	{
		printf("%c \r\n",word[i]);
		i++;
		
	}
*/
	for (int i=0; i<50; i++)
	{
		printf("%d, ",word[i]);

	}

	scanf("%s",(word+9));

	//*(word+2) = 0x00;
	//= word[2] = 0x00;
	 
	printf("your input is : %s \r\n",word);

	return 0;
}
