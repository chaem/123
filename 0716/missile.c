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
#include "missile.h"

///// normal missile /////
void missile_init(_S_MISSILE_OBJECT *pObj, double x, double y, double speed, _S_MAP_OBJECT *pBody)
{
	pObj->m_nFSM = 0;  //0:sleep, 1:active
	pObj->m_nStep = 0;
	pObj->m_fSpeed = speed;
	pObj->m_fXpos = x;
	pObj->m_fYpos = y;
	pObj->m_pBody = pBody;

}

void missile_apply(_S_MISSILE_OBJECT *pObj,
double deltaTick)
{
	switch (pObj->m_nFSM) {  //0:sleep, 1:active
		case 0:
		break;

		case 1:
		if (pObj->m_nStep == 0) {
			pObj->m_nStep++;
			pObj->m_faccLifeTime = 0;
	
		} else {
			pObj->m_faccLifeTime += deltaTick;  // Life time ++
			if (pObj->m_faccLifeTime > pObj->m_fLifeLimit) {
				pObj->m_nStep = 0;
				pObj->m_nFSM = 0;	
				
			}

			pObj->m_fYpos += deltaTick * (pObj->m_fSpeed * pObj->m_fvy); // speed=1  1s - 1 / =2  2s - 2 
			pObj->m_fXpos += deltaTick * (pObj->m_fSpeed * pObj->m_fvx);
		}

		break;

	}
	
}

void missile_draw(_S_MISSILE_OBJECT *pObj, _S_MAP_OBJECT *pMapBuf)
{
	switch (pObj->m_nFSM) {  //0:sleep, 1:active
		case 0:
		break;

		case 1:
		map_drawTile_trn(pObj->m_pBody, (int)pObj->m_fXpos, (int)pObj->m_fYpos, pMapBuf);
		break;

	}

}

void missile_fire(_S_MISSILE_OBJECT *pObj,
int x, int y,
double speed, double vx, double vy,
double lifeLimit)
{
	pObj->m_nFSM = 1;  //shoot
	pObj->m_nStep = 0;
	pObj->m_fXpos = (double)x;
	pObj->m_fYpos = (double)y;
	pObj->m_fvx = vx;
	pObj->m_fvy = vy;
	pObj->m_fSpeed = speed;
	pObj->m_fLifeLimit = lifeLimit;

}

///// Follow_missile /////
void follow_missile_init(_S_FOLLOW_MISSILE_OBJECT *pObj, double x, double y, double speed, _S_MAP_OBJECT *pBody)
{
	pObj->m_nFSM = 0;  //0:sleep, 1:active
	pObj->m_nStep = 0;

	pObj->m_fSpeed = speed;
	pObj->m_fXpos = x;
	pObj->m_fYpos = y;
	pObj->m_pBody = pBody;

}

void follow_missile_apply(_S_FOLLOW_MISSILE_OBJECT *pObj,
double deltaTick, int x)
{
	switch (pObj->m_nFSM) {  //0:sleep, 1:active
		case 0:
		break;

		case 1:
		if (pObj->m_nStep == 0) {
			pObj->m_nStep++;
			pObj->m_faccLifeTime = 0;
	
		} else {
			pObj->m_faccLifeTime += deltaTick;  // Life time ++
			if (pObj->m_faccLifeTime > pObj->m_fLifeLimit) {
				pObj->m_nStep = 0;
				pObj->m_nFSM = 0;	
				
			}

			pObj->m_fYpos += deltaTick * (pObj->m_fSpeed * pObj->m_fvy); // speed=1  1s - 1 / =2  2s - 2 
			pObj->m_fXpos += deltaTick * (pObj->m_fSpeed * pObj->m_fvx);
		}

		if (pObj->m_fYpos < 20) {
			if (x > pObj->m_fXpos) {
				pObj->m_fXpos += 1;

			}
			else if (x < pObj->m_fXpos) {
				pObj->m_fXpos -= 1;
			}

		}

		break;

	}
	
}

void follow_missile_draw(_S_FOLLOW_MISSILE_OBJECT *pObj, _S_MAP_OBJECT *pMapBuf)
{
	switch (pObj->m_nFSM) {  //0:sleep, 1:active
		case 0:
		break;

		case 1:
		map_drawTile_trn(pObj->m_pBody, (int)pObj->m_fXpos, (int)pObj->m_fYpos, pMapBuf);
		break;

	}

}

void follow_missile_fire(_S_FOLLOW_MISSILE_OBJECT *pObj,
int x, int y,
double speed, double vx, double vy,
double lifeLimit)
{
	pObj->m_nFSM = 1;  //shoot
	pObj->m_nStep = 0;
	pObj->m_fXpos = (double)x;
	pObj->m_fYpos = (double)y;
	pObj->m_fvx = vx;
	pObj->m_fvy = vy;
	pObj->m_fSpeed = speed;
	pObj->m_fLifeLimit = lifeLimit;

}