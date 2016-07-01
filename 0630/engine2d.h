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

// tile map engine
void map_printCell(int rawdata)
{
	switch(rawdata) {
		case 0: //
		printf(" ");
		break;
			
		case 1: //wall
		printf("#");
		break;
	
		case 2: //door
		printf("m");
		break;
		
		case 3:
		printf("A");
		break;
					
		default:
		printf(" ");
		break;
		}
}

void map_drawAll(int *pMap) //pointer
{
	int ix, iy;
	
	for(iy=0; iy<8; iy++) { //0~7
		for(ix=0; ix<8; ix++) { //0~7
			map_printCell(pMap[ix+iy*8]); //*****
			//printf("%d",world_map[ix+iy*8]); //*8 map size
		}
		printf("\r\n");
	
	}

}

#endif
