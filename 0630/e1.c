#include <stdio.h>

int main()
{
	char cmd;
	scanf("%c",&cmd);
	/*
	if(cmd == 'z') {
		printf("producing zealot.\r\n");
	}
	else if(cmd == 'd') {
		printf("producing dragon.\r\n");
	}
	else {
		printf("Please insert again.\r\n");
	}
	*/
	switch(cmd) {
		case 'c': //none break; if entered 'c' -> c~z /break;
		printf("producing career.\r\n");

		case 'z':
		printf("producing zealot.\r\n");
		break;

		case 'd':
		printf("producing dragon.\r\n");
		break;

		default: //else
		printf("Please insert again.\r\n");
	}

}
