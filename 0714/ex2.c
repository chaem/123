#include <stdio.h>
#include <math.h>

int main()
{
	printf("%f \r\n",sqrt(2.0));
	printf("%f \r\n",sqrt(3.0));
	printf("%f \r\n",sqrt(4.0));
	printf("%f \r\n",sqrt(16.0));


	double vx, vy;
	vx = 1.0;
	vy = 1.0;

	double vlength = sqrt((vx*vx)+(vy*vy));

	printf("vector length(1,1) : %f \r\n",vlength);

	vx /= vlength;
	vy /= vlength;

	printf("vector : %f, %f \r\n",vx/vlength,vy/vlength);


	vlength = sqrt(vx*vx + vy*vy);

	printf("vector length :%f \r\n",vlength);

	return 0;
}
