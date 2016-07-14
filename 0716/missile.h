#ifndef __MISSILE_H__
#define __MISSILE_H__

typedef struct 
{
	int m_nFSM;
	int m_nStep;

	//missile
	double m_fXpos;
	double m_fYpos;

	double m_fvx;  //vector
	double m_fvy;

	double m_fSpeed;
	double m_faccLifeTime;  // present life time
	double m_fLifeLimit;  // life

	_S_MAP_OBJECT *m_pBody;

} _S_MISSILE_OBJECT;

void missile_init(_S_MISSILE_OBJECT *pObj, double x, double y, double speed, _S_MAP_OBJECT *pBody);

void missile_apply(_S_MISSILE_OBJECT *pObj, double deltaTick);

void missile_draw(_S_MISSILE_OBJECT *pObj, _S_MAP_OBJECT *pMapBuf);

void missile_fire(_S_MISSILE_OBJECT *pObj,
int x, int y,
double speed, double vx, double vy,
double lifeLimit);

#endif
