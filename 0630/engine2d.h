#ifndef __ENGIINE_2D__
#define __ENGIINE_2D__

// setting color
void setColor(int fore_color,int back_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,back_color);
}

// location  y=line
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);
}

// create box
int drawMyBox(int nXpos,int nYpos,int nColor,int nSize)
{
	int ix,iy;

	setColor(30,nColor);
	ix = 0;
	for(iy = 0; iy <= nSize; iy++) {
		for(ix = 0; ix <= nSize; ix++) {
			gotoxy(ix+nXpos,iy+nYpos);
			printf(" ");

		}
		setColor(0,0);

	}
}
#endif
