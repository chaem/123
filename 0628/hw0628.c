#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int back_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,back_color);
}
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);
}
int main()
{
	system("clear");
	setColor(37,41);
	gotoxy(5,3);
	printf("b");
	gotoxy(7,3);
	printf("b");
	gotoxy(9,3);
	printf("b");
	gotoxy(11,3);
	printf("b");

	setColor(0,0);
	return 0;
}
