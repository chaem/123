#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <windows.h>

#include "engine/engine.c"
#include "../mapeditor/map.h"

int loading_screen[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,
    0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,0,0,2,2,2,2,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,2,2,2,0,0,0,0,2,2,2,2,2,0,0,2,2,2,2,0,0,0,0,0,
    0,0,1,0,0,0,2,0,0,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,1,0,0,
    0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,
    0,0,1,0,0,0,2,0,0,0,0,2,2,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,1,0,0,
    0,0,0,0,0,0,2,0,0,0,0,2,0,2,0,2,0,0,2,0,0,0,2,0,0,2,2,2,2,2,0,0,2,0,0,0,2,0,0,2,2,2,2,2,0,0,2,2,2,2,0,0,0,0,0,
    0,0,1,0,0,0,2,0,0,0,0,2,0,0,2,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,1,0,0,
    0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,
    0,0,1,0,0,0,2,0,0,0,0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,2,0,0,0,2,0,0,2,0,0,2,0,0,0,2,0,0,0,0,0,0,2,0,0,0,2,0,1,0,0,
    0,0,0,0,2,2,2,2,2,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,2,0,0,0,2,0,0,2,2,2,0,0,0,0,2,2,2,2,2,0,0,2,0,0,0,2,0,0,0,0,
    0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};  // 55 * 17

int bLoop = 1;
int nFSM = 0;
int nStep = 0;

struct timespec work_timer;
double acc_tick,last_tick;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gAlienModel;
_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gPlaneModel;
_S_MAP_OBJECT gLaserModel;

_S_ALIEN_OBJECT gTestAlienObject;
_S_BULLET_OBJECT gTestBulletObject;
_S_Plane gPlaneObject;
_S_LASER_OBJECT gLaserObject;

//////////////////////////////////////////////////////////
void gameStart_Title()
{
	char game_name[8] = "INVADER";
	double game_version = 1.01;

	int i = 0;
	switch(nStep) {
		case 0:
		if (i == 0) {
			sleep(1);
			draw_mainTitle(loading_screen);
			gotoxy(22,17);
			printf("%s ",game_name);
			setColor(33,40);
			printf("%.2lf \r\n",game_version);

			sleep(2);
			setColor(0,0);
			gotoxy(21,19);
			puts("Press to start!");
			nStep = 1;
			break;

		}
		case 1:
		if (kbhit() != 0) {
			char ch = getch();
			nFSM = 1;
			nStep = 0;
		}
		break;

	}

}

//////////////////////////////////////////////////////////
void gameStart_Play()
{
	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,22);

	}

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet1.dat");

	map_init(&gPlaneModel);
	map_load(&gPlaneModel,"plane1.dat");

	map_init(&gLaserModel);
	map_load(&gLaserModel,"plasma.dat");

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

}

/*=======================================================*/
int main()
{
    set_conio_terminal_mode();
	acc_tick = last_tick = 0;

 	while(bLoop) {
		// time process
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		// input
		if (nFSM == 0) {
			gameStart_Title(delta_tick);

		}
		else if (nFSM == 1) { 
			gameStart_Play();

		}

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
