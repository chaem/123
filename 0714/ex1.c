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

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer[2];
_S_MAP_OBJECT gMissile;
_S_MISSILE_OBJECT gMissileObject;

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	for (int i=0; i<2; i++) {
		map_init(&gScreenBuffer[i]);
		map_new(&gScreenBuffer[i],35,15);

	}
	map_init(&gMissile);
	map_load(&gMissile,"plasma.dat");
	missile_init(&gMissileObject,0,0,0,&gMissile);

	system("clear");	

	//target
	int targetx, targety;
	targety = 3;
	targetx = 2; 

	int fire_x = 24;
	int fire_y = 12;


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
			else if (ch == 'j') {
				double vx, vy, c;
				vx = targetx - fire_x;
				vy = targety - fire_y;
				c = sqrt(vx*vx + vy*vy);
				vx /= c;
				vy /= c;
		
				missile_fire(&gMissileObject,
				fire_x, fire_y, 1.0,
				vx, vy,
				10);
					
			}
			else if (ch == 'a') {
				target x -= 1;

			}
			else if (ch == 'd') {
				target x += 1;

			}

		}

		// apply location
		missile_apply(&gMissileObject,delta_tick);

		// time calculate
		acc_tick += delta_tick;
		if(acc_tick > 1.0) {
			//puts("tick...\r");
			map_drawTile(&gScreenBuffer[0],0,0,&gScreenBuffer[1]);
			missile_draw(&gMissileObject,&gScreenBuffer[1]);	
			gotoxy(0,0);
			
			map_PutTile(&gScreenBuffer[1],fire_x,fire_y,5);
			map_PutTile(&gScreenBuffer[1],targetx,targety,5);

			map_dump(&gScreenBuffer[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
