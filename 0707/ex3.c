#include <stdio.h>

struct _S_PLAYER
{
	int m_nHp;
	int m_nMp;

};

int main()
{
	struct _S_PLAYER player1 = {100, 50}; // {m_nHp, m_nMp}
	printf("HP : %d \r\n",player1.m_nHp);	
	printf("MP : %d \r\n",player1.m_nMp);

	struct _S_PLAYER player2;
	player2 = player1; // copy player1 -> player2
	printf("HP : %d \r\n",player2.m_nHp);
	printf("MP : %d \r\n",player2.m_nMp);

	struct _S_PLAYER *pPlayer;
	pPlayer = &player1; // pointer refer - sharing address

	pPlayer->m_nHp = 240;
	pPlayer->m_nMp = 120;

	printf("HP : %d \r\n",player1.m_nHp);
	printf("MP : %d \r\n",player1.m_nMp);

	return 0;
}
