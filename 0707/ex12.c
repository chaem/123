#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char m_szName[32];
	int m_nHp;

} _S_PLAYER;

int main()
{
	_S_PLAYER player = {
		"chaemin",
		100
	};

	FILE *pf = fopen("test.dat","wb");

	fwrite(&player,sizeof(_S_PLAYER),1,pf); // 1 - buffer number 
	fclose(pf);

	return 0;
}
