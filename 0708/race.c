#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "engine2d.h"
#include "race.h"


char screen_buffer[8*8];

struct timespec work_timer;
double acc_tick, last_tick;
double rock_acc_tick;

int rock_pos_x, rock_pos_y;
int rock_pos_table[8] = {1,5,2,7,3,5,2,6}; 
int rock_cur_table_index = 0;

struct timespec work_timer;
set_conio_terminal_mode();
	
int bLoop = 1;
int car_posx, car_posy;

static int nFSM = 0; //status
static int nStep = 0'

void rg_PlayGame(double delta_tick) {
	switch (nStep) {
		case 0:
		nStep++;
		system("clear");
		break;

		case 1:


		//user input	
		if (kbhit() != 0) {
			char ch = getch();
			if (ch == 'q') { // quit
				bLoop = 0;

			} else if (ch == 'j') { // left
				car_posy -= 1;

			} else if (ch == 'l') { // right
				car_posy += 1;

			}

		}

		//obstacle - move
		rock_acc_tick += delta_tick;
		if (rock_acc_tick > 0.5) {
			rock_acc_tick = 0;
			rock_pos_x += 1;
			// - end	
			if (rock_pos_y >= 8) {
				rock_pos_y = 0;
				rock_cur_table_index++;
				rock_cur_table_index %= 8;
				rock_pos_x = rock_pos_table[rock_cur_table_index]; 
			}

		}

		//game logic (crush - game over)
		if (rock_pos_y == car_posy && rock_pos_x == car_posx) {
			bLoop = 0;
			printf("Game over! \n");

		}

		//buffer reset
		for(int i=0; i<64; i++) {
			screen_buffer[i] = 0;

		}

		//print car
		screen_buffer[ car_posy*8 + car_posx ] = 2;
		//print obstacle
		screen_buffer[ rock_pos_y*8 + rock_pos_x ] = 1;

		acc_tick += delta_tick;
		if (acc_tick > 0.1 || bLoop == 0) {
			acc_tick = 0;
			drawGame(8,8,screen_buffer);
		}

	}

}

void rg_apply_mainTitle() {

	char game_name = "Drag Racing";
	double game_version = "1.01";
	char game_version2 = 'a';
	

	switch (nStep) {
		case 0:
		printf("%s \r\n",game_name);
		printf("%.2lf",game_version);
		printf("%c \r\n",game_verison2);

		puts("press to start");
		nStep = 1;
		break;

		case 1:
		if (kbhit() != 0) {
			char ch = getch();
			nFSM = 1;
			nStep = 0;

		}
		break;

	}

}

int main()
{
	

	//buffer reset
	for(int i=0; i<64; i++) {
		screen_buffer[i] = 0;

	}
	
	set_conio_terminal_mode();
	
	acc_tick = last_tick = 0;
	system("clear");

	car_posy = 4;
	car_posx = 2;

	rock_pos_y = 0;
	rock_pos_x = rock_pos_table[rock_cur_table_index];

	while (bLoop) {
		//timing
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec +
		(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
	
		if (nFSM == 0) { //ready
			rg_apply_mainTitle(delta_tick);	
					
		} else if (nFSM == 1) { //game start
			rg_PlayGame(delta_tick);

		} else {

		}

	}

	return 0;

}
