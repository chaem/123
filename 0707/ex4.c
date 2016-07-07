#include <stdio.h>
#include <string.h>

struct _S_PLAYER
{
	char m_szName[128];
	int m_nHp;	

};

int main()
{
	struct _S_PLAYER players[] = {
		{"lee jin gi", 300},
		{"lee chae min", 500},
		{"kim dong yeong", 700}
	};

	for (int i=0; i<3; i++) {
		printf("name : %s, hp : %d \r\n",
		players[i].m_szName,players[i].m_nHp);

	}

	return 0;
}
