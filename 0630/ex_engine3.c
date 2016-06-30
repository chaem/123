#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"
/*
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
*/

// error
void drawMyBox(int as,int df,int color) 
{
	int x,y;
	x = 1;
	y = 1;

	setColor(30,color);
 	while(x <= 4) {
		y = 1;
		while(y <= 2) {
			gotoxy(x+as,y+df);
			printf(" ");
			y++;
		
		}
		x++;
	}
	setColor(0,0);

}

int main()
{
	system("clear");
	
	drawMyBox(1,10); // draw all
	drawMyBox(10,20);

	setColor(30,44);
	gotoxy(0,45);
	printf("           ");
	setColor(0,0);
	
	return 0;
}
