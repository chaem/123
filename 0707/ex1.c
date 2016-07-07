#include <stdio.h>
#include <string.h>

struct _S_HUMAN { // _S_ - struct
	// m_ - member
	int m_nHp; // n - int
	int m_nMp;
	int m_nLevel;
	char m_szName[128]; // sz- string / end z
	double m_dbAp; // db - double / Ap - action point
};
/*
C++
class _S_HUMAN

int main()
_S_HUMAN human
 */

int main()
{
	struct _S_HUMAN human;

	human.m_nHp = 100;
	human.m_nMp = 50;
	human.m_nLevel = 1;
	human.m_dbAp = 3.5;
	strcpy(human.m_szName,"bringiton");

	printf("hp : %d \r\n",human.m_nHp);
	printf("mp : %d \r\n",human.m_nMp);
	printf("level : %d \r\n",human.m_nLevel);
	printf("ap : %f \r\n",human.m_dbAp);
	printf("name : %s \r\n",human.m_szName);
	return 0;
}
