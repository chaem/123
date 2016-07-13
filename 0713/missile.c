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

			pObj->m_fYpos -= deltaTick * pObj->m_fSpeed; // speed=1  1s - 1 / =2  2s - 2 
		
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

void missile_fire(_S_MISSILE_OBJECT *pObj, int x, int y, double speed, double lifeLimit)
{
	pObj->m_nFSM = 1;  //shoot
	pObj->m_nStep = 0;
	pObj->m_fXpos = (double)x;
	pObj->m_fYpos = (double)y;
	pObj->m_fSpeed = speed;
	pObj->m_fLifeLimit = lifeLimit;

}

