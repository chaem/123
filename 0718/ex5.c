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

_S_MAP_OBJECT gPlaneModel;
_S_MAP_OBJECT gAlienModel;
_S_MAP_OBJECT gBulletModel;  //alienAttack
_S_MAP_OBJECT gLaserModel;  //playerAttack

_S_Plane gPlaneObject;
_S_ALIEN_OBJECT gTestAlienObject[8];
_S_BULLET_OBJECT gTestBulletObject;  //alienAttack
_S_LASER_OBJECT gLaserObject;  //playerAttack

int main()
{

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,40);

	}

	map_init(&gPlaneModel);
	map_load(&gPlaneModel,"player.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet1.dat");

	map_init(&gLaserModel);
	map_load(&gLaserModel,"arrow.dat");

	double TablePosition[] = {0,6.0,12.0,18.0,24.0,30.0};
	for(int i=0;i<6;i++)
	{
		_S_ALIEN_OBJECT *pObj = &gTestAlienObject[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = TablePosition[i];
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;
	}

	Plane_init(&gPlaneObject,&gPlaneModel,0,0);
	bullet_init(&gTestBulletObject,0,0,0,&gBulletModel);
	laser_init(&gLaserObject,0,0,0,&gLaserModel);

	gTestAlienObject[0].m_pBullet = &gTestBulletObject;
	
	gPlaneObject.m_fXpos = 17;
	gPlaneObject.m_fYpos = 38;
	gPlaneObject.m_nFSM = 1;
	
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

		for(int i=0;i<6;i++ ) 
			{
				_S_ALIEN_OBJECT *pObj = &gTestAlienObject[i];
				pObj->pfApply(pObj,delta_tick);

			}
			
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

		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);

			gPlaneObject.pfDraw(&gPlaneObject,&gScreenBuf[1]);
			for(int i=0;i<6;i++ ) 
			{
				_S_ALIEN_OBJECT *pObj = &gTestAlienObject[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}
			gTestBulletObject.pfDraw(&gTestBulletObject,&gScreenBuf[1]);
			gLaserObject.pfDraw(&gLaserObject,&gScreenBuf[1]);

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
