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
			
		case 1: // wall
		setColor(31,43);
		printf("¢È");
		break;
	
		case 2: // locked door
		setColor(36,40);
		printf("m");
		break;
		
		case 3: // me
		setColor(37,40);
		printf("O");
		break;
		
		case 4: // opened door
		printf("M");			
		break;

		case 5: // key
		setColor(33,40);
		printf("Y");
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
