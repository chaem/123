#include <stdio.h>
#include <stdlib.h>
#include "../0630/engine2d.h"

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
		printf("���� �̵��߽��ϴ� \r\n");
		player_ypos -= 1;
		break;

		case 'j':
		printf("�������� �̵��߽��ϴ� \r\n");
		player_xpos -= 1;
		break;

		case 'l':
		printf("���������� �̵��߽��ϴ� \r\n");
		player_xpos += 1;
		break;

		case 'k':
		printf("�Ʒ��� �̵��߽��ϴ� \r\n");
		player_ypos += 1;
		break;

	}
		//**
	if(buffer_map[player_xpos + player_ypos*8] == 0) {
		 
	} else {
		//printf("���ٸ� ���Դϴ� \r\n");
		player_xpos = old_xpos;
		player_ypos = old_ypos;
	}

}

int main()
{
	//�����
	char cmd;
	int bLoop = 1;

	while(bLoop)
	{
		printf("����� �����ϼ���.(i(up),j(left),l(right),k(down),s(show map),q(quit)");
		//*moving A not copied
		for(int i = 0; i < 64; i++)
		{
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
