#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"

int main()
{
	system("clear"); //window clean
	int x = 1;
	int y;

	setColor(30,41);
	while(x <= 7) {
		y = 1;
		while(y <= 10) {
			gotoxy(10+y,10+x);
			printf(" ");
			y++;
		}
		setColor(30,41+x);
		x++;
	}

	setColor(0,0); //reset color
	gotoxy(0,30);
	printf("==============="); //end

	return 0;
}
