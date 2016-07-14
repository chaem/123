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


	double angle = 90;
	for (int i=0; i<35; i++) {
		angle = (double) i * (180 / 35);  //sin
		//printf("%f \r\n",sin( (angle/180) * PI) );	
		double my = sin( (angle/180) * PI) * 8.0;  // 10.0 - scalla

		map_PutTile(&ScreenBuf, i, 8 + my, 1);

		my = cos(angle/180 * PI) * 8.0;  //cos
		map_PutTile(&ScreenBuf, i, 8 + my, 2);

	}
	map_dump(&ScreenBuf, Default_Tilepalete);

	return 0;
}
