#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int back_color) //색상
{
	printf("%c[%d;%dm",0x1b,fore_color,back_color);	
}
void gotoxy(int x, int y) //위치
{
	printf("%c[%d;%df",0x1b,y,x); //줄, 열
}
int main()
{
	system("clear");
	/* 적 */
	setColor(37,41);
	gotoxy(20,10); // 꼭대기
	printf(" ");
	gotoxy(19,11);
	printf(" ");
	gotoxy(18,12);
	printf(" ");
	gotoxy(20,11);
	printf(" ");
	gotoxy(19,12);
	printf(" ");
	gotoxy(18,13);
	printf(" ");
	gotoxy(18,14);
	printf(" ");
	gotoxy(18,15);
	printf(" ");
	gotoxy(18,16);
	printf(" ");
	gotoxy(18,17);
	printf(" ");
	gotoxy(18,18);
	printf(" ");
	gotoxy(18,19);
	printf(" ");
	gotoxy(18,20);
	printf(" ");
	gotoxy(18,21);
	printf(" ");
	gotoxy(18,22);
	printf(" ");
	gotoxy(18,23);
	printf(" ");
	gotoxy(21,11);
	printf(" ");
	gotoxy(22,12);
	printf(" ");
	gotoxy(22,13);
	printf(" ");
	gotoxy(22,14);
	printf(" ");
	gotoxy(22,15);
	printf(" ");
	gotoxy(22,16);
	printf(" ");
	gotoxy(22,17);
	printf(" ");
	gotoxy(22,18);
	printf(" ");
	gotoxy(22,19);
	printf(" ");
	gotoxy(22,20);
	printf(" ");
	gotoxy(22,21);
	printf(" ");
	gotoxy(22,22);
	printf(" ");
	gotoxy(22,23);
	printf(" ");
	gotoxy(21,12);
	printf(" ");
	gotoxy(17,13); // 왼쪽 시작
	printf(" ");
	gotoxy(17,14);
	printf(" ");
	gotoxy(17,15);
	printf(" ");
	gotoxy(17,16);
	printf(" ");
	gotoxy(17,17);
	printf(" ");
	gotoxy(17,18);
	printf(" ");
	gotoxy(17,19);
	printf(" ");
	gotoxy(17,20);
	printf(" ");
	gotoxy(17,21);
	printf(" ");
	gotoxy(17,22);
	printf(" ");
	gotoxy(17,23);
	printf(" ");
	gotoxy(17,24);
	printf(" ");
	gotoxy(17,24); // 왼쪽 끝
	printf(" ");
	gotoxy(21,11);
	printf(" ");
	gotoxy(22,12);
	printf(" ");
	gotoxy(23,13); // 오른쪽 시작
	printf(" ");
	gotoxy(23,14);
	printf(" ");
	gotoxy(23,15);
	printf(" ");
	gotoxy(23,16);
	printf(" ");
	gotoxy(23,17);
	printf(" ");
	gotoxy(23,18);
	printf(" ");
	gotoxy(23,19);
	printf(" ");
	gotoxy(23,20);
	printf(" ");
	gotoxy(23,21);
	printf(" ");
	gotoxy(23,22);
	printf(" ");
	gotoxy(23,23);
	printf(" ");
	gotoxy(23,24);
	printf(" "); // 오른쪽 끝

	gotoxy(23,25);
	printf(" ");
	gotoxy(24,25); // 오른쪽 튀어나온 부분
	printf(" ");
	gotoxy(22,25);
	printf(" ");
	gotoxy(21,25);
	printf(" ");
	gotoxy(20,25);
	printf(" ");
	gotoxy(19,25);
	printf(" ");
	gotoxy(18,25);
	printf(" ");
	gotoxy(17,25);
	printf(" ");
	gotoxy(16,25);
	printf(" "); // 왼쪽 튀어나온 부분
	gotoxy(22,26);
	printf(" ");
	gotoxy(22,27);
	printf(" ");
	gotoxy(22,28);
	printf(" ");
	gotoxy(22,29);
	printf(" ");
	gotoxy(22,30);
	printf(" ");
	gotoxy(22,31);
	printf(" ");
	gotoxy(22,32);
	printf("-");
	gotoxy(21,32);
	printf("-");
	gotoxy(20,32);
	printf("-");
	gotoxy(19,32);
	printf("-");
	gotoxy(18,32); // 손잡이 왼쪽끝
	printf("-");
	gotoxy(18,31);
	printf(" ");
	gotoxy(18,30);
	printf(" ");
	gotoxy(18,29);
	printf(" ");
	gotoxy(18,28);
	printf(" ");
	gotoxy(18,27);
	printf(" ");
	gotoxy(18,26);
	printf(" ");
	gotoxy(19,30);
	printf(" ");
	gotoxy(20,30);
	printf(" ");
	gotoxy(21,30);
	printf(" ");
	gotoxy(18,28);
	printf(" ");
	gotoxy(19,28);
	printf(" ");
	gotoxy(20,28);
	printf(" ");
	gotoxy(21,28);
	printf(" ");

	setColor(31,43);
	gotoxy(20,12);
	printf("*");
	gotoxy(20,13);
	printf("*");
	gotoxy(19,13);
	printf("*");
	gotoxy(21,13);
	printf("*");
	gotoxy(20,14);
	printf("*");
	gotoxy(20,15);
	printf("*");
	gotoxy(19,15);
	printf("*");
	gotoxy(21,15);
	printf("*");
	gotoxy(20,16);
	printf("*");
	gotoxy(20,17);
	printf("*");
	gotoxy(19,17);
	printf("*");
	gotoxy(21,17);
	printf("*");
	gotoxy(20,18);
	printf("*");
	gotoxy(20,19);
	printf("*");
	gotoxy(19,19);
	printf("*");
	gotoxy(21,19);
	printf("*");
	gotoxy(20,20);
	printf("*");
	gotoxy(20,21);
	printf("*");
	gotoxy(19,21);
	printf("*");
	gotoxy(21,21);
	printf("*");
	gotoxy(20,22);
	printf("*");
	gotoxy(20,23);
	printf("*");
	gotoxy(19,23);
	printf("*");
	gotoxy(21,23);
	printf("*");
	gotoxy(20,24);
	printf("*");

	setColor(31,43);
	gotoxy(19,31);
	printf("=");
	gotoxy(20,31);
	printf("=");
	gotoxy(21,31);
	printf("=");
	gotoxy(19,29);
	printf("=");
	gotoxy(20,29);
	printf("=");
	gotoxy(21,29);
	printf("=");
	gotoxy(19,27);
	printf("=");
	gotoxy(20,27);
	printf("=");
	gotoxy(21,27);
	printf("=");


	/* 백 */
	setColor(30,47);
 	// 튀어나온 부분
	gotoxy(16,23);
	printf(" ");
	gotoxy(16,22);
	printf(" ");
	gotoxy(16,21);
	printf(" ");
	gotoxy(16,20);
	printf(" ");
	gotoxy(16,19);
	printf(" ");
	gotoxy(16,18);
	printf(" ");
	gotoxy(16,17);
	printf(" ");
	gotoxy(16,16);
	printf(" ");
	gotoxy(16,15);
	printf(" ");
	gotoxy(16,14);
	printf(" ");
	gotoxy(16,13);
	printf(" ");
	gotoxy(17,12);
	printf(" ");
	gotoxy(18,11);
	printf(" ");
	gotoxy(19,10);
	printf(" ");
	gotoxy(20,9); // 흰색 꼭대기
	printf(" ");
	gotoxy(21,10);
	printf(" ");
	gotoxy(22,11);
	printf(" ");
	gotoxy(23,12);
	printf(" ");
	gotoxy(24,13);
	printf(" ");
	gotoxy(24,14);
	printf(" ");
	gotoxy(24,15);
	printf(" ");
	gotoxy(24,16);
	printf(" ");
	gotoxy(24,17);
	printf(" ");
	gotoxy(24,18);
	printf(" ");
	gotoxy(24,19);
	printf(" ");
	gotoxy(24,20);
	printf(" ");
	gotoxy(24,21);
	printf(" ");
	gotoxy(24,22);
	printf(" ");
	gotoxy(24,23);
	printf(" ");
	
	gotoxy(60,60);
	printf("");
	setColor(0,0);
	return 0;
}
