#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>

#include "../engine/engine2d.h"
#include "../mapeditor/map.h"
#include "missile.h"
#include "plane.h"
#include "tower.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer[2];  //screen
_S_MAP_OBJECT gPlayer;  //player
_S_MAP_OBJECT gTower;  //tower
_S_MAP_OBJECT gMissile;  //missile
_S_MAP_OBJECT gFollow_missile;  //follow_missile

_S_Plane gPlayerObject;
_S_TOWER gTowerObject;
_S_MISSILE_OBJECT gMissileObject;  //m_obj
_S_FOLLOW_MISSILE_OBJECT gFollow_missileObject;

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	system("clear");

	for (int i=0; i<2; i++) {
		map_init(&gScreenBuffer[i]);
		map_new(&gScreenBuffer[i],50,20);

	}
	// plane
	int plane_x, plane_y;
	plane_x = 5;
	plane_y = 8;
	map_init(&gPlayer);
	map_load(&gPlayer,"plane.dat");  //not
	Plane_init(&gPlayerObject,&gPlayer,plane_x,plane_y);  // ?
	
	// tower
	int tower_x, tower_y;
	tower_x = 40;
	tower_y = 15;
	map_init(&gTower);
	map_load(&gTower,"tower.dat");  //not
	Tower_init(&gTowerObject,&gTower,tower_x,tower_y);

	// missile
	map_init(&gMissile);
	map_load(&gMissile,"missile.dat");  //not
	missile_init(&gMissileObject,0,0,0,&gMissile);

	// follow_missile
	map_init(&gFollow_missile);
	map_load(&gFollow_missile,"follow_missile.dat");
	follow_missile_init(&gFollow_missileObject,0,0,0,&gFollow_missile);

	system("clear");	

	while(bLoop) {
		//time process
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		//input
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
			else if (ch == 'p') {
				double vx, vy, c;
				vx = plane_x - tower_x;
				vy = plane_y - tower_y;
				c = sqrt(vx*vx + vy*vy);
				vx /= c;
				vy /= c;
		
				missile_fire(&gMissileObject,
				tower_x, tower_y,
				20.0, vx, vy,
				10);
					
			} /*
			else if (ch == 'l') {
				double

				follow_missile_fire(&gFollow_missileObject,
				20.0,tower_x, tower_y,
				20.0, vx, vy, theta,
				10)


			} */

			Plane_Apply(&gPlayerObject,delta_tick,ch);

		}

		// apply location
		missile_apply(&gMissileObject,delta_tick);


		// time calculate
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			//puts("tick...\r");
			map_drawTile(&gScreenBuffer[0],0,0,&gScreenBuffer[1]);
			
			Plane_Draw(&gPlayerObject,&gScreenBuffer[1]);
			Tower_Draw(&gTowerObject,&gScreenBuffer[1]);
			missile_draw(&gMissileObject,&gScreenBuffer[1]);
			gotoxy(0,0);
	
			map_dump(&gScreenBuffer[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
