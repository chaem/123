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
_S_MAP_OBJECT gAlienModel;  //alien2
_S_MAP_OBJECT gBulletModel;  //alien2
_S_MAP_OBJECT gAlienModel2;  //alien3
_S_MAP_OBJECT gBulletModel2;  //alien3
_S_MAP_OBJECT gLaserModel;  //playerAttack

_S_Plane gPlaneObject;
_S_ALIEN_OBJECT gTestAlienObject[10];  //alien2
_S_BULLET_OBJECT gTestBulletObject[10];  //alien2
_S_ALIEN_OBJECT2 gTestAlienObject2[5];  //alien3
_S_BULLET_OBJECT gTestBulletObject2[5];  //alien3
_S_BULLET_OBJECT gLaserObject[32];  //playerAttack

int main()
{

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,30);

	}
	map_init(&gPlaneModel);
	map_load(&gPlaneModel,"player.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien2.dat");

	map_init(&gAlienModel2);
	map_load(&gAlienModel2,"alien3.dat");

	map_init(&gBulletModel2);
	map_load(&gBulletModel2,"fol_bullet.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet1.dat");

	map_init(&gLaserModel);
	map_load(&gLaserModel,"arrow.dat");

	Plane_init(&gPlaneObject,&gPlaneModel,0,0);

	double TablePosition[] = {-50.0, -45.0, -40.0, -35.0, -30.0, -25.0, -20.0, -15.0, -10.0, -5.0};
	double TablePosition2[] = {45,40,35,30,25};

	//alien2
	for(int i=0;i<10;i++)
	{
		_S_ALIEN_OBJECT *pObj = &gTestAlienObject[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = TablePosition[i];
		pObj->m_fYpos = 5;
		pObj->m_nFSM = 1;
		gTestAlienObject[i].m_pBullet = &gTestBulletObject[i];
	}

	//alien3
	for(int i=0;i<5;i++)
	{
		_S_ALIEN_OBJECT2 *pObj = &gTestAlienObject2[i];
		alien_init2(pObj,&gAlienModel2);
		pObj->m_fXpos = TablePosition2[i];
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;
		gTestAlienObject2[i].m_pBullet = &gTestBulletObject2[i];
	}
	
	//player attack
	for (int i=0; i<sizeof(gLaserObject)/sizeof(_S_BULLET_OBJECT); i++) {
		_S_BULLET_OBJECT *pObj = &gLaserObject[i];
		bullet_init(&gLaserObject[i],0,0,0,&gLaserModel);
	}

	//alien2 attack
	for (int i=0; i<sizeof(gTestBulletObject)/sizeof(_S_BULLET_OBJECT); i++) {
		_S_BULLET_OBJECT *pObj = &gTestBulletObject[i];
		bullet_init(&gTestBulletObject[i],0,0,0,&gBulletModel);
	}

	//alien3 attack
	for (int i=0; i<sizeof(gTestBulletObject2)/sizeof(_S_BULLET_OBJECT); i++) {
		_S_BULLET_OBJECT *pObj = &gTestBulletObject2[i];
		bullet_init(&gTestBulletObject2[i],0,0,0,&gBulletModel2);
	}

	gPlaneObject.m_fXpos = 17;
	gPlaneObject.m_fYpos = 28;
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
				for (int i=0; i<sizeof(gLaserObject)/sizeof(_S_BULLET_OBJECT); i++) {
					double vx, vy, c;

					vx = gTestAlienObject[i].m_fXpos-gPlaneObject.m_fXpos;
					vy = gTestAlienObject[i].m_fYpos-gPlaneObject.m_fYpos;
					c = sqrt(vx*vx + vy*vy);
					vx /= c;
					vy /= c;

					_S_BULLET_OBJECT *pObj = &gLaserObject[i];
					if (pObj->m_nFSM == 0) {
						pObj->pfFire(pObj,
						gPlaneObject.m_fXpos,
						gPlaneObject.m_fYpos,
						25.0,0,vy,3.0);
					}

				}

			}

			gPlaneObject.pfApply(&gPlaneObject,delta_tick,ch);

		}

		for (int i=0; i<sizeof(gLaserObject)/sizeof(_S_BULLET_OBJECT); i++) {
			_S_BULLET_OBJECT *pObj = &gLaserObject[i];
			pObj->pfApply(pObj,delta_tick);

		}

		//alien2
		for (int i=0; i<10; i++) {
			_S_ALIEN_OBJECT *pObj = &gTestAlienObject[i];
			pObj->pfApply(pObj,delta_tick);
		}

		//alien3
		for (int i=0; i<5; i++) {
			_S_ALIEN_OBJECT2 *pObj = &gTestAlienObject2[i];
			pObj->pfApply2(pObj,delta_tick);
		}

		//alien2 - attack
		for (int i=0; i<sizeof(gTestBulletObject)/sizeof(_S_BULLET_OBJECT); i++) {
			_S_BULLET_OBJECT *pObj = &gTestBulletObject[i];
			pObj->pfApply(pObj,delta_tick);

		}

		//alien3 - attack
		for (int i=0; i<sizeof(gTestBulletObject2)/sizeof(_S_BULLET_OBJECT); i++) {
			_S_BULLET_OBJECT *pObj = &gTestBulletObject2[i];
			pObj->pfApply(pObj,delta_tick);

		}

		// alien dead
		for (int i=0; i<sizeof(gLaserObject)/sizeof(_S_BULLET_OBJECT); i++) {
			double laser_pos_x = gLaserObject[i].m_fXpos;
			double laser_pos_y = gLaserObject[i].m_fYpos;

			double target_pos_x = gTestAlienObject[i].m_fXpos;
			double target_pos_y = gTestAlienObject[i].m_fYpos;

			double vx = target_pos_x - laser_pos_x;
			double vy = target_pos_y - laser_pos_y;
			double dist  = sqrt(vx*vx+vy*vy);
			if(dist < 2) {
				gTestAlienObject[i].m_nFSM = 0;
				
			}
		
		}

		// user dead
		for (int i=0; i<sizeof(gTestBulletObject)/sizeof(_S_BULLET_OBJECT); i++) {
			double bullet_pos_x = gTestBulletObject[i].m_fXpos;
			double bullet_pos_y = gTestBulletObject[i].m_fYpos;

			double user_pos_x = gPlaneObject.m_fXpos;
			double user_pos_y = gPlaneObject.m_fYpos;

			double v2x = bullet_pos_x - user_pos_x;
			double v2y = bullet_pos_y - user_pos_y;
			double dist  = sqrt(v2x*v2x+v2y*v2y);
			if(dist < 2) {
				gPlaneObject.m_nFSM = 0;
				
			}
		
		}

		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);

			gPlaneObject.pfDraw(&gPlaneObject,&gScreenBuf[1]);

			//alien2
			for(int i=0; i<10; i++ )
			{
				_S_ALIEN_OBJECT *pObj = &gTestAlienObject[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}

			//alien3
			for(int i=0; i<5; i++ )
			{
				_S_ALIEN_OBJECT2 *pObj = &gTestAlienObject2[i];
				pObj->pfDraw2(pObj,&gScreenBuf[1]);
			}

			//alien2 attack
			for (int i=0; i<10; i++) {
				gTestBulletObject[i].pfDraw(&gTestBulletObject[i],&gScreenBuf[1]);
			}

			//alien3 attack
			for (int i=0; i<5; i++) {
				gTestBulletObject2[i].pfDraw(&gTestBulletObject2[i],&gScreenBuf[1]);
			}

			for (int i=0; i<sizeof(gLaserObject)/sizeof(_S_BULLET_OBJECT); i++) {
				_S_BULLET_OBJECT *pObj = &gLaserObject[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
