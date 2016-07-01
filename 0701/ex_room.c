#include <stdio.h>
#include <stdlib.h>
#include "../0630/engine2d.h"
#include "ex_room.h"

int main()
{
	//�����
	char cmd;
	int bLoop = 1;

	while(bLoop)
	{
		printf("����� �����ϼ���.(i(up),j(left),l(right),k(down),s(show map),q(quit)");
		//*moving A not copied
		for(int i = 0; i < 64; i++)	{
			buffer_map[i] = world_map[i]; //copy / original - world_map
		}
		scanf("%c",&cmd);
		getchar();	
		move_player(cmd);
		
		//*
		buffer_map[player_xpos + player_ypos*8] = 3; //location "A"
		
		switch(cmd) {
			case 's':
			printf("���� �����ݴϴ� \r\n");
			//*
			map_drawAll(buffer_map);
			break;

			case 'q':
			bLoop = 0;
			printf("bye bye \r\n");
			break;

		}

	}

	return 0;

}
