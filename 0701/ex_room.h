#ifndef __EXIT_ROOM_H__
#define __EXIT_ROOM_H__

int buffer_map[64];

//0 ready
//1 start
//2 over
//3 ?
int nFSM = 0;

int player_xpos;
int player_ypos;
int player_inven; //0 - none , 1 - key

void move_player(char cmd)
{
	int old_xpos = player_xpos;
	int old_ypos = player_ypos;

	switch(cmd)
	{
		case 'i':
			player_ypos -=1;
			break;
		case 'j':
			player_xpos -=1;
			break;
		case 'k':
			player_xpos += 1;
			break;
		case 'm':
			player_ypos += 1;
			break;
	}

	switch(buffer_map[ player_xpos + player_ypos*8 ] ) {

		case 0: //space
			break;
		case 1: //wall
			player_ypos = old_ypos;
			player_xpos = old_xpos;
			break;
		case 2: //door
			if(player_inven = 0)
			{
			printf("We need a key \r\n");
			player_ypos = old_ypos;
			player_xpos = old_xpos;
			} 
			else if(player_inven = 1)
			{
				printf("Victory! \r\n");

			}
			break;
			
		case 4:
			if(player_inven ==1) {
				printf("ë¯¸ì…˜í´ë¦¬ì–´ \r\n");
				nFSM = 2;
			}
			else {
				player_ypos = old_ypos;
				player_xpos = old_xpos;

			}
			break;
		case 5:
			printf("í‚¤ë¥¼ ì–»ì—ˆìŠµë‹ˆë‹¤. \r\n");
			player_inven = 1;

			break;

	}

	buffer_map[ player_xpos + player_ypos*8 ] = 3; //3¹ (User) °è¼Ó Âï¾îÁÜ

}

#endif

