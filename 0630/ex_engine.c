#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h" //하위 폴더 일 경우 ../engine2d.h

int main()
{
	system("clear");

	//loop문으로 직선 긋기
	int i=0; //reset
	int y=0;

	int a=1;
	int b=9;

	int ix,iy;
	ix = 1;
	iy = 1;
	/* cross */
	while(i<10) {
		gotoxy(10,i);
		printf("+");
		i++;
	
	}
	while(y<8) {
		gotoxy(6+y,3);
		printf("+");
		y++;
	
	}

	/* across */
	while(a<=9) {
		setColor(36,40); //cyan color
		gotoxy(a,20+a);
		printf("O");
		a++;
	
	}
	while(b>0) {
		setColor(36,40);
		gotoxy(b,30-b);
		printf("O");
		b--;
	
	}


	setColor(0,0); //none color
	gotoxy(0,40); //end 한계점은 항상 마지막 설정
	printf("=====================");
	return 0;
}
