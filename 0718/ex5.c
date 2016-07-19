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
#include "bullet.h"
#include "alien.h"
#include "plane.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gAlienModel;
_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gPlaneModel;
_S_MAP_OBJECT gLaserModel;

_S_ALIEN_OBJECT gTestAlienObject;
_S_BULLET_OBJECT gTestBulletObject;
_S_Plane gPlaneObject;
_S_LASER_OBJECT gLaserObject;

int main()
{

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,22);

	}

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet.dat");

	map_init(&gPlaneModel);
	map_load(&gPlaneModel,"plane.dat");

	map_init(&gLaserModel);
	map_load(&gLaserModel,"laser.dat");

	alien_init(&gTestAlienObject,&gAlienModel);
	bullet_init(&gTestBulletObject,0,0,0,&gBulletModel);
	Plane_init(&gPlaneObject,&gPlaneModel,0,0);
	laser_init(&gLaserObject,0,0,0,&gLaserModel);

	gTestAlienObject.m_pBullet = &gTestBulletObject;
	
	gPlaneObject.m_fXpos = 17;
	gPlaneObject.m_fYpos = 20;
	gPlaneObject.m_nFSM = 1;
	gTestAlienObject.m_fXpos = -10;
	gTestAlienObject.m_fYpos = 1;
	gTestAlienObject.m_nFSM = 1;
	
	system("clear");
	
	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간 입력
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
			else if (ch =='p') {  //laser
				double bullet_pos_x = gTestBulletObject.m_fXpos;
				double bullet_pos_y = gTestBulletObject.m_fYpos;
			
				double target_pos_x = gPlaneObject.m_fXpos;
				double target_pos_y = gPlaneObject.m_fYpos;

				double vx = target_pos_x - bullet_pos_x;
				double vy = target_pos_y - bullet_pos_y;
				double dist  = sqrt(vx*vx+vy*vy);
				vx /= dist;
				vy /= dist;

				gLaserObject.pfFire(&gLaserObject,
				gPlaneObject.m_fXpos,gPlaneObject.m_fYpos,
				-1,0,gPlaneObject.m_fYpos,15);

			}

			gPlaneObject.pfApply(&gPlaneObject,delta_tick,ch);

		}

		//gPlaneObject.pfApply(&gPlaneObject,delta_tick,ch);


		gTestAlienObject.pfApply(&gTestAlienObject,delta_tick);
		gTestBulletObject.pfApply(&gTestBulletObject,delta_tick);
		gLaserObject.pfApply(&gLaserObject,delta_tick);

		if (gTestBulletObject.m_nFSM != 0) {
			double bullet_pos_x = gTestBulletObject.m_fXpos;
			double bullet_pos_y = gTestBulletObject.m_fYpos;

			double target_pos_x = gPlaneObject.m_fXpos;
			double target_pos_y = gPlaneObject.m_fYpos;

			double vx = target_pos_x + bullet_pos_x;
			double vy = target_pos_y + bullet_pos_y;
			double dist  = sqrt(vx*vx+vy*vy);

			if(dist < 2) {
				gTestBulletObject.m_nFSM = 0;
				gPlaneObject.m_nFSM = 0;
				
			}

		}
			/*
			if(dist < 2) {
				gTestBulletObject.m_nFSM = 0;
				gPlaneObject.m_nFSM = 0;
			}
			*/
		
/*
		if (gLaserObject.m_nFSM != 0) {
				double laser_pos_x = gLaserObject.m_fXpos;
				double laser_pos_y = gLaserObject.m_fYpos;
			
				double target_pos_x2 = gTestAlienObject.m_fXpos;
				double target_pos_y2 = gTestAlienObject.m_fYpos;

				double v2x = target_pos_x2 + laser_pos_x;
				double v2y = target_pos_y2 + laser_pos_y;
				double dist2  = sqrt(v2x*v2x+v2y*v2y);
				v2x /= dist2;
				v2y /= dist2;

				if(dist2 < 2) {
				gLaserObject.m_nFSM = 0;
				gTestAlienObject.m_nFSM = 0;
			}
		}
*/		
		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);

			setColor(33,40);
			gPlaneObject.pfDraw(&gPlaneObject,&gScreenBuf[1]);
			gTestAlienObject.pfDraw(&gTestAlienObject,&gScreenBuf[1]);
			gTestBulletObject.pfDraw(&gTestBulletObject,&gScreenBuf[1]);
			gLaserObject.pfDraw(&gLaserObject,&gScreenBuf[1]);

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
