#include <stdio.h>

void reset
{
	for (int i=0; i<64; i++)
	{
		buffer[i] = 0;

	}

};

int main()
{
	int bLoop;
	char cmd;
	char buffer[64];
	int Index = 0;

	bLoop = 1;
	while(bLoop)
	{
		scanf("%c",&cmd);
		getchar();

		switch(cmd)
		{
			case 'a': //add
			break;

			case 'd': //back delete
			break;

			case 'f': //front delete
			break;

			case 's': //show
			break;
		}

	}

	return 0;
}
