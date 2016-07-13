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
#include "missile.h"

struct timespec work_timer;
double acc_tick, last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer;  // screen
_S_MAP_OBJECT gPlaneObj;  // Plane1
_S_MAP_OBJECT gSpace;  // copy-screen
_S_MAP_OBJECT gMissileObj;  // missile


int xpos, ypos;  // location

//missile
_S_MISSILE_OBJECT g_missiles[32];


// game object admit?
_S_Plane gPlayerPlane;

int main()
{
	set_conio_terminal_mode();
	acc_tick = last_tick = 0;
	system("clear");
	map_init(&gScreenBuffer);
	map_new(&gScreenBuffer,35,16);  // original

	map_init(&gPlaneObj);
	map_load(&gPlaneObj,"plane1.dat");

	map_init(&gSpace);
	map_new(&gSpace,35,16);  // copy

	//missile
	map_init(&gMissileObj);
	map_load(&gMissileObj,"missile.dat");
	
	Plane_init(&gPlayerPlane,&gPlaneObj,17,10);

	//missile
	for (int i=0; i<sizeof(g_missiles)/sizeof(_S_MISSILE_OBJECT); i++) {
		missile_init(&g_missiles[i],0,0,0,&gMissileObj);

	}

	while (bLoop) {
		// time process 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		
		// in time_input
		if (kbhit() != 0) {
			char ch = getch();
			if (ch == 'q') {
				bLoop = 0; // exit
				puts("bye~ \r");

			}
			//missile shoot
			else if (ch == 'o') {
				for (int i=0; i<sizeof(gMissileObj)/sizeof(_S_MISSILE_OBJECT); i++) {
					_S_MISSILE_OBJECT *pObj = &g_missiles[i];
					if (pObj->m_nFSM == 0) {  // status = sleep
						missile_fire(pObj,gPlayerPlane.m_nXpos,gPlayerPlane.m_nYpos,10,5.0);
						break;  // 1shoot

					}

				}
			}
			Plane_Apply(&gPlayerPlane,delta_tick,ch); 

		}
		//missile - memory full
		for (int i=0; i<sizeof(gMissileObj)/sizeof(_S_MISSILE_OBJECT); i++) {
			_S_MISSILE_OBJECT *pObj = &g_missiles[i];
			missile_apply(pObj,delta_tick);	
		}

		// time calculate
		acc_tick += delta_tick;
		if (acc_tick > 0.1) {
			map_drawTile(&gSpace,0,0,&gScreenBuffer);  // screen clear
			Plane_Draw(&gPlayerPlane,&gScreenBuffer);	
			//map_drawTile_trn(&gPlane,xpos,ypos,&gScreenBuffer);
			
			Plane_Draw(&gPlayerPlane,&gScreenBuffer);
			
			//missile
			for (int i=0; i<sizeof(gMissileObj)/sizeof(_S_MISSILE_OBJECT); i++) {
				_S_MISSILE_OBJECT *pObj = &g_missiles[i];
				if (pObj->m_nFSM == 1) {
					missile_draw(pObj,&gScreenBuffer);
					
				}

			}

			gotoxy(0,0);
			puts("------------------------------\r");
			map_dump(&gScreenBuffer, Default_Tilepalete);
			puts("------------------------------\r");

			puts("move : w, a, s, d \r");
			puts("quit : q \r");

			acc_tick = 0;

		}


	}


	return 0;
}
