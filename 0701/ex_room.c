#include <stdio.h>
#include <stdlib.h>
#include "../0630/engine2d.h"
#include "ex_room.h"

/*
 1 : wall (#)
 2 : opend door (M)
 3 : gamer (A)
 4 : locked door (m)
 5 : open key (Y)
 */

//map
int world_map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,0,1,0,0,0,2,
	1,0,0,1,0,0,0,1,
	1,0,0,0,0,5,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int game_version = 100;
char *game_name = "Escape Game";

int player_inven; //0=none / 1=have a key

int main()
{
	//동기식
	char cmd;
	int bLoop = 1;

	while(bLoop)
	{
		switch(nFSM) {
			case 0:
			printf("Welcome to %s. \r\n %d \r\n",game_name,game_version);
			printf("select => [p,x] \r\n");
			break;
			
			case 1:
			printf("명령을 선택하세요.\r\n(i(up),j(left),l(right)\r\n,k(down),s(show map),q(quit)\r\n");
			break;
			
			case 2:
			break;
		
		}

		for(int i = 0; i < 64; i++)	{
			buffer_map[i] = world_map[i]; //copy / original - world_map
		
		}

		scanf("%c",&cmd);
		getchar();	
		
		if(nFSM == 0) //ready
		{
			switch(cmd) {
				case 'p': //start
				nFSM = 1;
				player_ypos = 5;
				player_xpos = 1;
				player_inven = 0; //none key
				printf("game start!");
				break;
				
				case 'x':
				bLoop = 0;
				printf("bye \r\n");
				break;
			}
		}
		else if(nFSM == 1) { //play
			move_player(cmd);
		
			switch(cmd) {
				case 's':
				printf("맵을 보여줍니다 \r\n");
				map_drawAll(buffer_map);
				break;

				case 'q':
				bLoop = 0;
				printf("bye bye \r\n");
				break;
			}

		}
		else if(nFSM == 2) {
			nFSM = 0;
				
		}

	}

	return 0;

}
