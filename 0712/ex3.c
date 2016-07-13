#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main()
{

	char TilePalette[] = {'.', '#', '@'};
	_S_MAP_OBJECT carObj;
	map_init(&carObj);
	
	map_load(&carObj,"car.dat");
	puts("\r\n======================");

	map_dump(&carObj,TilePalette);

	return 0;
}
