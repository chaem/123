#ifndef __EXITROOM_H__
#define __EXIT_ROOM_H__

//map
int world_map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,0,1,0,0,0,2,
	1,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int buffer_map[64]; //***

int player_xpos = 1;
int player_ypos = 5;

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
		//**
	if(buffer_map[player_xpos + player_ypos*8] == 0) {
		 
	} else {
		//printf("막다른 길입니다 \r\n");
		player_xpos = old_xpos;
		player_ypos = old_ypos;
	}

}

#endif
