#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"
#include "../mapeditor/map.h"
#include "plane.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];
_S_MAP_OBJECT gPlayer;

_S_Plane gPlayerObject;

int main()
{
	system("clear");

	for (int i=0; i<2; i++) {
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,16);

	}

	map_init(&gPlayer);
	map_load(&gPlayer,"plane1.dat");

	Plane_init(&gPlayerObject,&gPlayer,17,10);

	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	while(bLoop) {
		// time process
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		
		// input
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
			//Plane_Apply(&gPlayerObject,delta_tick,ch);
			gPlayerObject.fpApply(&gPlayerObject,delta_tick,ch);

		}
		// time acculate
		acc_tick += delta_tick;
		
		if(acc_tick > 1.0) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			
			gPlayerObject.fpDraw(&gPlayerObject.&gScreenBuf[1]);  // &gPlayerObject = this pointer
			//Plane_Draw(&gPlayerObject,&gScreenBuf[1]);

			map_dump(&gScreenBuf[1],Default_Tilepalete);

			//puts("tick...\r");
			acc_tick = 0;
		}

	}

	return 0;

}
