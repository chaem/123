#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myeditor.h"

int main()
{
	puts("editor version 1.0");

	_S_STR_LINE *pHeader = NULL;

	int bLoop = 1;

	while (bLoop) {
		char *pTemp;
		char strCmd[128];
		gets(strCmd);

		pTemp = strtok(strCmd," ");

		if (!strcmp(pTemp,"exit")) { // == 0
			bLoop = 0;

		} else if (!strcmp(pTemp,"push")) { //add
			pTemp = strtok(NULL," ");
			char *pstr = (char *)malloc(strlen(pTemp)+1);
			strcpy(pstr,pTemp);
			
			_S_STR_LINE *pLine = (_S_STR_LINE *)malloc(sizeof(_S_STR_LINE));
			pLine->m_szStr = pstr;
			pLine->m_pNext = NULL;
			if (pHeader == NULL) {
				pHeader = pLine;

			} else {
				//find ~end
				_S_STR_LINE *pNext = (_S_STR_LINE *)pHeader;

				while (pNext != NULL) {
					// if end
					if (pNext->m_pNext == NULL) {
						pNext->m_pNext = pLine;
						pNext = NULL; // exit loop	

					} else { // if more 
						pNext = pNext->m_pNext;

					}

				}

			}

		} else if (!strcmp(pTemp,"pop")) { // back delete
			
		} else if (!strcmp(pTemp,"del")) { // front delete
			_S_STR_LINE *_pGarbage = m_pNext;
			pHeader = pHeader->m_pNext;

			free(_pGarbage->m_szStr);
			free(_pGarbage);

		} else if (!strcmp(pTemp,"ins")) { // insert data
			int nIndex = atoi(strtok(NULL," "));
			pTemp = strtok(NULL,"");
			printf("%d, %s add \r\n",nIndex,pTemp);

		} else if (!strcmp(pTemp,"rm")) { // delete wanted data
			int nIndex = atoi(strtok(NULL," "));
				
		} else if(!strcmp(pTemp,"set")) { //change data
			int nIndex = atoi(strtok(NULL," "));
		
		} else if (!strcmp(pTemp,"dump")) { // show list
			puts("----------------------------");
			// first line
			_S_STR_LINE *pLine = pHeader;
			puts(pLine->m_szStr);
			// another line
			while (pLine != NULL) {
				puts(pLine->m_szStr);
				pLine = pLine->m_pNext; //***** 
			}
				
			puts("----------------------------");

		}

	}

	return 0;
}
