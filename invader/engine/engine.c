#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <windows.h>

#include "engine.h"

////////////////////////////////////////////////////////////
struct termios orig_termios;

void reset_terminal_mode()
{
	tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
	struct termios new_termios;

	/* take two copies - one for now, one for later */
	tcgetattr(0, &orig_termios);
	memcpy(&new_termios, &orig_termios, sizeof(new_termios));

	/* register cleanup handler, and set the new terminal mode */
	atexit(reset_terminal_mode);
	cfmakeraw(&new_termios);
	tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}

int getch()
{
	int r;
	unsigned char c;
	if ((r = read(0, &c, sizeof(c))) < 0) {
		return r;
	} else {
		return c;
	}
}

/////////////////// console graphic ////////////////////////
void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);

}

///////////////////// loading screen ////////////////////////
void loadingScreen () {
	int i, j;

	///// top
	setColor(30,41);
	for (i=6; i<57; i += 2) {
		gotoxy(i, 5);
		printf(" ");

	}

	///// bottom
	for (i=6; i<57; i += 2) {
		gotoxy(i, 15);
		printf(" ");

	}
	
	///// side
	for (i=6; i<15; i += 2) {
		gotoxy(5, i);
		printf(" ");
		gotoxy(57, i);
		printf(" ");

	}

	///// edge
	gotoxy(5, 5);
	printf(" ");
	gotoxy(57, 5);
	printf(" ");
	gotoxy(5, 15);
	printf(" ");
	gotoxy(57, 15);
	printf(" ");

	setColor(37,43);
	///// character(I)
	for (i=8; i<13; i++) {
		gotoxy(i, 7);
		printf("*");
		gotoxy(i, 13);
		printf("*");

	}
	for (i=8; i<13; i++) {
		gotoxy(10, i);
		printf("*");

	}

	///// character(N)
	for (i=7; i<14; i++) {
		gotoxy(15, i);
		printf("*");
		gotoxy(19, i);
		printf("*");

	}
	gotoxy(17, 10);
	printf("*");
	gotoxy(16, 9);
	printf("*");
	gotoxy(18, 11);
	printf("*");

	///// character(V)
	for (i=7; i<12; i++) {
		gotoxy(22, i);
		printf("*");
		gotoxy(26, i);
		printf("*");

	}
	gotoxy(23, 12);
	printf("*");
	gotoxy(24, 13);
	printf("*");
	gotoxy(25, 12);
	printf("*");

	///// character(A)
	for (i=9; i<14; i++) {
		gotoxy(29, i);
		printf("*");
		gotoxy(33, i);
		printf("*");

	}
	gotoxy(30, 8);
	printf("*");
	gotoxy(31, 7);
	printf("*");
	gotoxy(32, 8);
	printf("*");
	gotoxy(32, 10);
	printf("*");
	gotoxy(31, 10);
	printf("*");
	gotoxy(30, 10);
	printf("*");

	///// character (D)
	for (i=7; i<14; i++) {
		gotoxy(36, i);
		printf("*");

	}
	for (i=9; i<12; i++) {
		gotoxy(40, i);
		printf("*");

	}
	gotoxy(37, 7);
	printf("*");
	gotoxy(38, 7);
	printf("*");
	gotoxy(39, 8);
	printf("*");
	gotoxy(37, 13);
	printf("*");
	gotoxy(38, 13);
	printf("*");
	gotoxy(39, 12);
	printf("*");

	///// character (E)
	for (i=7; i<14; i++) {
		gotoxy(43, i);
		printf("*");
	}
	for (i=44; i<48; i++) {
		gotoxy(i, 7);
		printf("*");
		gotoxy(i, 10);
		printf("*");
		gotoxy(i, 13);
		printf("*");

	}

	///// character (R)
	for (i=7; i<14; i++) {
		gotoxy(50, i);
		printf("*");

	}
	gotoxy(51, 7);
	printf("*");
	gotoxy(52, 7);
	printf("*");
	gotoxy(53, 7);
	printf("*");
	gotoxy(54, 8);
	printf("*");
	gotoxy(54, 9);
	printf("*");
	gotoxy(53, 10);
	printf("*");
	gotoxy(52, 10);
	printf("*");
	gotoxy(51, 10);
	printf("*");
	gotoxy(54, 11);
	printf("*");
	gotoxy(54, 12);
	printf("*");
	gotoxy(54, 13);
	printf("*");

	setColor(0,0);

	///// game start
	gotoxy(22, 17);
	printf("Press Any Key!");

}