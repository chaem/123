#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int m_nHp;
	char m_szName[128];

} _S_Player;

/* C++
class _S_Player {

}
 */

// typedef struct _S_PLAYER _S_Player

int main()
{
	_S_Player player = {
		100,
		"bringiton",
	};

	puts(player.m_szName);

	return 0;
}
