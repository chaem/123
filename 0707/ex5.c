#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _S_PLAYER {
	char m_szName[128];
	int m_nHp;

};

int main()
{
	struct _S_PLAYER *pPlayer;

	pPlayer = (struct _S_PLAYER *)malloc(sizeof(struct _S_PLAYER));

	strcpy(pPlayer->m_szName,"bringiton");
	pPlayer->m_nHp = 100;

	free(pPlayer); // assigned memory return

	return 0;	
}
