#include <stdio.h>

int num1 = 7; //���� ����

void test() //'test' void �Լ�
{
	printf("%d \r\n",num1);
}

int main() //main �Լ�
{
	int num1 = 3;

	{
		//int num1 = 4;
		num1 = 4;
		printf("%d \r\n",num1); //1
	}
	//scope �������� ������ ���� �̸����� �ٸ� �� ��� ����

	printf("%d \r\n",num1); //2

	test(); // �'test'�Լ� ȣ��
	return 0;
}
