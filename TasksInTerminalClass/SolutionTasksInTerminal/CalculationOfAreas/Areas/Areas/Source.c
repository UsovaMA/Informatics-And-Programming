#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "russian");
	printf("������ �� ���� ����������� \n");
	float x1, x2, y1, y2, r1, r2;
	float d;
	printf("������� ��������� 1-� ���������� (� ���� x y r): ");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("������� ��������� 2-� ���������� (� ���� x y r): ");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if (d == r1 + r2)
	{
		printf("��������");;
	}
	if (d < r1 + r2)
	{
		if (d == 0 && r1 == r2)
		{
			printf("���������");
		}
		else if (d + r1 < r2 || d + r2 < r1)
		{
			printf("���� ������ ������");
		}
		else if (d == abs(r1 - r2)) 
		{
			printf("�������� ������ ");
		}
		else {
			printf("������������");
		}
	}
	if (d > r1 + r2)
	{
		printf("�� ������������");
	}
	return 0;
}