#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../mapeditor/map.h"
#include "../engine/engine2d.h"

#define PI 3.141592
// a : 180 == b : PI
//b = a/180 * PI

int main()
{
	_S_MAP_OBJECT ScreenBuf;
	map_init(&ScreenBuf);
	map_new(&ScreenBuf,35,17);	

	system("clear");
	gotoxy(0,0);

	double target_x = 14;
	double target_y = 4;

	double center_x = 14;
	double center_y = 8;
	
	map_PutTile(&ScreenBuf,center_x,center_y,5);	 
	map_PutTile(&ScreenBuf,target_x,target_y,2);

	for (int i=0; i<180; i++) {
		double rad = ((double)i/180.0) * PI;
		double tx, ty;
		tx = (target_x - center_x) * cos(rad) - (target_y - center_y) * sin(rad);
		ty = (target_x - center_x) * sin(rad) + (target_y - center_y) * cos(rad);
		tx += center_x;
		ty += center_y;
		
		map_PutTile(&ScreenBuf,tx,ty,1);

		
	}
	

	/*
	for (int i=0; i<35; i++) {
		angle = (double) i * (180 / 35);
		//printf("%f \r\n",sin( (angle/180) * PI) );	
		double my = sin( (angle/180) * PI) * 8.0;  //sin
		map_PutTile(&ScreenBuf, i, 8 + my, 1);

		my = cos(angle/180 * PI) * 8.0;  //cos
		map_PutTile(&ScreenBuf, i, 8 + my, 2);

	}
	*/
	map_dump(&ScreenBuf, Default_Tilepalete);

	return 0;
}
