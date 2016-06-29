#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int back_color) //함수
{
	printf("%c[%d;%dm",0x1b,fore_color,back_color);
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x); //줄, 열

}

int main()
{
	int fore_color; //변수 생성
	fore_color = 32;
	/* "\x1b[31m" = "%c[31m",0x1b*/
	system("clear");
	printf("%c[31m",0x1b);
	printf("hello");

	gotoxy(3,3);
	setColor(32,44);
	//printf("%c[%dm",0x1b,fore_color);
	printf("programming");
	setColor(33,45);
	printf("world");
	setColor(0,0);	//reset ANSI command
	gotoxy(0,20);
	printf("==========================");
	return 0;
}
