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
#include "tower.h"


void Tower_init(_S_TOWER *pObj, _S_MAP_OBJECT *pBody, int x, int y)
{
	pObj->m_pBody = pBody;
	pObj->m_nYpos = y;
	pObj->m_nXpos = x;

}

void Tower_Apply(_S_TOWER *pObj, double deltaTick, char key_input)
{
	switch(key_input) {
		case 'p': //not
		pObj->m_nYpos -= 1;
		break;

	}

}

void Tower_Draw(_S_TOWER *pObj, _S_MAP_OBJECT *pBuff)
{
	map_drawTile_trn(pObj->m_pBody,pObj->m_nXpos,pObj->m_nYpos,pBuff);

}