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
//////////////////// Title ////////////////////
void titleCell(int data)
{
    switch(data) {
        case 0:
			setColor(0,0);
            printf(" ");
            break;
        case 1:
			setColor(37, 41);  //white, red
            printf(" ");  //LINE
            break;
        case 2:
			setColor(37, 43);  //white, Yellow
            printf("*");  //INVADER
            break;

    }

}

void draw_mainTitle(int *dt)
{
    int x, y;

    for (y=0; y<17; y++) {
        for (x=0; x<55; x++) {
            titleCell(dt[x+y*55]);

        }
        printf("\r\n");

    }
}

//////////////////// time ////////////////////
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

//////////////////// cmd ////////////////////
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
