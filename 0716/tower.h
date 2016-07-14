#ifndef __TOWER_H__
#define __TOWER_H__

typedef struct
{
	int m_nXpos;
	int m_nYpos;
	_S_MAP_OBJECT *m_pBody;

} _S_TOWER;

void Tower_init(_S_TOWER *pObj, _S_MAP_OBJECT *pBody, int x, int y);
void Tower_Apply(_S_TOWER *pObj, double deltaTick, char key_input);
void Tower_Draw(_S_TOWER *pObj, _S_MAP_OBJECT *pBuff);



#endif
