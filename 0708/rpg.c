#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *m_szName;
	void *node[8];
} _S_AREA;

int main()
{
	_S_AREA town = {
		"town",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL
	};

	_S_AREA dungeon_1 = {
		"dungeon-1",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL
	};

	town.node[0] = &dungeon_1;
	dungeon_1.node[0] = &town;

	_S_AREA *pCurrentArea = &town;
	
	int bLoop = 1;
	while (bLoop) {
		char szCmd[32];
		gets(szCmd);
		char *pTemp = strtok(szCmd," ");
		
		if (!strcmp(pTemp,"look")) {
			printf("Here is %s. \r\n",pCurrentArea->m_szName);
			
		} else if (!strcmp(pTemp,"move")) {
			char *pszArea = strtok(NULL,""); 	
			printf("moving %s.",pszArea);
			
			for (int i=0; i<8; i++) {
				_S_AREA *pNode = pCurrentArea->node[i]; 
				if (pNode == NULL) break;
				if (!strcmp(pNode->m_szName,pszArea)) {
					printf("success. \r\n");
					pCurrentArea = pNode;

				}

			}
				
		} else if (!strcmp(pTemp,"exit")) {
			bLoop = 0;

		}
		
	}

	return 0;
}
