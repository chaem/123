#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"

int main()
{
	system("clear");

	int ix,iy;
	ix = 1;
	iy = 1;

	setColor(30,42); //green
	while(ix <= 4) {
		iy = 1; //*
		while(iy <= 2) {
			gotoxy(10+ix,10+iy);
			printf(" ");
			iy++;

		}
		setColor(30,42+ix);
		ix++;

	}

	setColor(0,0); //reset color
	gotoxy(0,30);
	printf("===============");

	return 0;
}
