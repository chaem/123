#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int back_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,back_color);
}
void gotoxy(int x,int y);
{
	printf("%c[%d;%df",0x1b,y,x);
}
int main()
{
	system("clear");
	setColor(37,41);
	gotoxy(5,3);
	printf("A");
	gotoxy(7,3);
	printf("A");
	gotoxy(9,3);
	printf("A");
	
	return 0;
}
