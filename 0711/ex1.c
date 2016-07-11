#include <stdio.h>

void draw_line (int n)
{
	for (int i=0; i<n; i++) {
		putchar('*');
	
	}

}

void draw_line2 (int n, char c)
{
	for (int i=0; i<n; i++) {
		putchar(c);

	}

}

void draw_quad()
{
	int ix, iy;
	for (iy = 0; iy < 10; iy++) {
		for (ix = 0; ix < 10; ix++) {
			putchar('*');

		}
		puts("");

	}

}

void draw_tri()
{
	int ix, iy;
	for (ix = 10; ix > 0; ix--) {
		for (iy = 0; iy < ix; iy++) {
			putchar('*');	
		}
		puts("");

	}

}

void draw_tri2()
{
	int ix, iy;
	for (iy = 0; iy < 10; iy++) {
		draw_line(iy);
		puts("");

	}

}

void draw_tri3()
{
	int ix, iy;
	for (iy = 0; iy < 10; iy++) {
		draw_line2(9-iy,' '); draw_line2((iy*2)+1,'*');
		puts("");

	}

}

void draw_pmd()
{
	int ix, iy;
	for (iy = 10; iy < 12; iy++) {
		for (ix = 0; ix < 4; ix++) { 
			draw_line2(5,' '); draw_line2(9,'*');
			puts("");

		}

	}

}

int main()
{
	draw_quad();
	draw_tri();
	draw_tri2();
	draw_tri3();
	draw_pmd();

	/* »ç°¢Çü
	for (iy = 0; iy < 10; iy++) {
		for (ix = 0; ix < 10; ix++) {
			putchar('*');

		}
		puts("");

	}
	*/

	return 0;
}
