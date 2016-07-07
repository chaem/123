#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char m_szName[32];
	int m_nHp;

} _S_PLAYER;

int main()
{
	_S_PLAYER player;

	FILE *pf = fopen("test.dat","rb");

	fread(&player,sizeof(_S_PLAYER),1,pf); // 1 - buffer number 
	fclose(pf);

	return 0;
}
