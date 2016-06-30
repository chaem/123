#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"
/*
 nxpos -> 'n' -> int
 ex) cxpos -> 'c' -> char
 */

int main()
{
	int bLoop = 1;
	char cmd;
	int xpos,ypos;
	xpos = 1;ypos = 1;

	int orc_xpos,orc_ypos;
	orc_ypos = 10;
	orc_xpos = 10;
	
	while(bLoop) {
		scanf("%c",&cmd);

		switch(cmd) {
			case 'u': //up
			ypos -= 1;
			break;
			
			case 'd': //down
			ypos += 1;
			break;			

			case 'r': //right
			xpos += 1;
			break;

			case 'l': //left
			xpos -= 1;
			break;

			case 'q': //quit
			bLoop = 0;
			break; 
			
		}

		system("clear");
		//ÁÖÀÎ°ø Ãâ·Â
		drawMyBox(xpos,ypos,44,2);
		
		//¸÷AI
		if(orc_xpos > xpos) {
			orc_xpos -= 1;
		}
		else if(orc_xpos < xpos) {
			orc_xpos += 1;
		} 
		else {
			
		}
		//¸÷ Ãâ·Â
		drawMyBox(orc_xpos,orc_ypos,42,4);
		gotoxy(0,20);
		printf("                   ");


		printf("%d,%d \r",xpos,ypos);

	}	

	return 0;
}
