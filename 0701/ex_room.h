#ifndef __EXITROOM_H__
#define __EXIT_ROOM_H__


int buffer_map[64]; //***

//0 ready
//1 play
//2 clear
//3 over
int nFSM = 0;

int player_xpos = 1;
int player_ypos = 5;
int player_inven; //0=none / 1=have key

void move_player(char cmd)
{
	int old_xpos = player_xpos;
	int old_ypos = player_ypos;

	switch(cmd)
	{
		case 'i':
		printf("위로 이동했습니다 \r\n");
		player_ypos -= 1;
		break;

		case 'j':
		printf("왼쪽으로 이동했습니다 \r\n");
		player_xpos -= 1;
		break;

		case 'l':
		printf("오른쪽으로 이동했습니다 \r\n");
		player_xpos += 1;
		break;

		case 'k':
		printf("아래로 이동했습니다 \r\n");
		player_ypos += 1;
		break;

	}

	switch(buffer_map[player_xpos + player_ypos*8])
	{
		//space
		case 0:
		break;

		//can't through the wall
		case 1:
		player_ypos = old_ypos;
		player_xpos = old_xpos;
		break;
		
		//door - clear
		case 2:
		printf("Victory \r\n");
		nFSM = 2;
		break;

		case 4:
			if(player_inven == 1) {
				printf("Misson Clear \r\n");
				nFSM = 2;

			} else {
				player_ypos = old_ypos;
				player_xpos = old_xpos;

			}
		break;
		
		case 5: //take key - disappear key
		printf("we have a key! \r\n");
		player_inven = 1;
		
		break;

	}
	
	buffer_map[player_xpos + player_ypos*8] = 3; //location "A"

}

#endif
