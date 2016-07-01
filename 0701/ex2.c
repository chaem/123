#include <stdio.h>

int num1 = 7; //Àü¿ª º¯¼ö

void test() //'test' void ÇÔ¼ö
{
	printf("%d \r\n",num1);
}

int main() //main ÇÔ¼ö
{
	int num1 = 3;

	{
		//int num1 = 4;
		num1 = 4;
		printf("%d \r\n",num1); //1
	}
	//scope °³º°ÀûÀÎ º¯¼ö·Î °°Àº ÀÌ¸§À¸·Î ´Ù¸¥ °ª Ãâ·Â °¡´É

	printf("%d \r\n",num1); //2

	test(); // Ç'test'ÇÔ¼ö È£Ãâ
	return 0;
}
