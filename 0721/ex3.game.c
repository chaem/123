#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>
#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#include "../engine/engine2d.h"
#include "../mapeditor/map.h"

#include "packet.h"
#include "plane.h"


pthread_t tid;
struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

int socket_desc;
char read_buffer[2000];

int gnPlayerIndex;


_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gPlayerModel;

_S_Plane gPlayerObject[2];  // 2player

typedef struct _S_PACKET_RECV_POSITIONS
{		
	unsigned short header;  // 2
	unsigned short type;  // 2
	float m_afXpos[2];  // 8
	float m_afYpos[2];  // 8  =20

} _S_PACKET_RECV_POSITIONS;

void *ListenThread(void *arg)
{
	while(1) {
		if(recv(socket_desc,
			read_buffer,2000,0) < 0) {
			//puts("recv failed");
		}
		_S_PACKET_RECV_POSITIONS *pPacket = 
			(_S_PACKET_RECV_POSITIONS *)read_buffer;		
		if (pPacket->header == 1004) {
			//player
			gPlayerObject[0].m_fXpos = pPacket->m_afXpos[0];
			gPlayerObject[0].m_fYpos = pPacket->m_afYpos[0];
			//player2
			gPlayerObject[1].m_fXpos = pPacket->m_afXpos[1];
			gPlayerObject[1].m_fYpos = pPacket->m_afYpos[1];	
		}
		
	}
	return NULL;

}

void *InputThread(void *arg)
{
	//ghost obejct
	float xpos = 0;
	float ypos = 0;

	while(1)
	{
		if(kbhit() != 0 ) {

			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}

			//gPlayerObject.pfApply(&gPlayerObject,0,ch);
			switch (ch) {
				case 'w':
					ypos -= 1;
					break;
				case 's':
					ypos += 1;
					break;
				case 'a':
					xpos -= 1;
					break;
				case 'd':
					xpos += 1;
					break;
			}

			_S_PACKET_REQ_SETPOS packet_setpos = {
				{
					1004,
					200,
				},
				gnPlayerIndex,
				xpos,
				ypos
			};
			if(send(socket_desc,
						&packet_setpos,
						sizeof(packet_setpos),0) < 0) {
				puts("send failed");
			}

		}

	}
	return NULL;
}


int main(int argc, char *argv[])
{
	if (argc < 2) {
		gnPlayerIndex = 0;
	}
	else {
		gnPlayerIndex = atoi(argv[1]);
	}
	printf("ready player %d \r\n",gnPlayerIndex);

// socket connecting try
	struct sockaddr_in server;

	socket_desc = socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc == -1)
	{
		puts("err create socket");
	}
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	if(connect(socket_desc,(struct sockaddr *)&server,sizeof(server)) < 0) {
		puts("connect error");
		return 1;
	}

	puts("connect ok!");
// thread operate
	{
		int err = pthread_create(&tid,NULL,&InputThread,NULL);
		if(err != 0) {
			printf("err : %s \r\n",strerror(err));
		}
		else {
			printf("thread create success \r\n");
		}
	}

	{
		int err = pthread_create(&tid,NULL,&ListenThread,NULL);
		if(err != 0) {
			printf("err : %s \r\n",strerror(err));
		}
		else {
			printf("thread create success \r\n");
		}
	}
	puts("sytemp ready!");
	sleep(3);

// game resource loading
	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,16);
	}

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane1.dat");

	Plane_init(&gPlayerObject[0],&gPlayerModel,0,0);
	gPlayerObject[0].m_nFSM = 1;

	Plane_init(&gPlayerObject[1],&gPlayerModel,0,0);
	gPlayerObject[1].m_nFSM = 1;

	puts("object setup complete!");
	sleep(1);	
	system("clear");

	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	while(bLoop) {
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
		
			gPlayerObject[0].pfDraw(&gPlayerObject[0],&gScreenBuf[1]);
			gPlayerObject[1].pfDraw(&gPlayerObject[1],&gScreenBuf[1]);

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
