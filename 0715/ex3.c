#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _S_ITEM_
{
	char m_szName[32];

	int m_nType;
	int m_nValue;

} _S_ITEM_;

_S_ITEM_ item_list[] = {
	{"short sword",0,10},
	{"wood shield",0,5},
	{"dagger",0,6},
	{"sling",0,3},
	{"staff",0,7}
};


_S_ITEM_ *findItem(const char *szName)
{
	int item_list_length = sizeof(item_list)/sizeof(_S_ITEM_);
	for (int i=0; i<item_list_length; i++) {
		_S_ITEM_ *pitem = &(item_list[i]);

		if (strcmp(szName,pitem->m_szName) == 0) {

			return pitem;
		}

	}

}


///// hash /////
unsigned long getHashCode(const char *szStr)
{
	int nLength = strlen(szStr);

	int nHash = 5381;  //seed value
	
	for (int i=0; i<nLength; i++) {
		//printf("%d \r\n",szStr[i]);
		//nHash += szStr[i];
		int c = szStr[i];
		nHash = ((nHash << 5) + nHash) + c;

	}

	return nHash;
}


int main()
{
	printf("%d \r\n",getHashCode("staff"));
	printf("%d \r\n",getHashCode("staeg"));

	//_S_ITEM_ *pItem = findItem("staff");
	//printf("%s %d \r\n",pItem->m_szName,pItem->m_nValue);
	/*
	printf("%d, %d \r\n",getHashCode("staff"),getHashCode("step"));
	if (getHashCode("staff") == getHashCode("step")) {
		puts(" same. ");

	}
	else {
		puts(" different. ");

	}
	*/
	return 0;
}
