#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() //��������� ������ ���������
{
	setlocale(LC_ALL, "Russian"); // ��������� ����� �� ������� ����

	/* ������� x1, y1 ������ ����������, � ��� �� �� R*/

	printf("������� ���������� I ����������: \n");
	int x1, y1;
	scanf_s("%d %d", &x1, &y1);

	printf("������� ������ I ����������: \n");

	int r1;
	scanf_s("%d", &r1);

	/* ������� x2, y2 ������ ����������, � ��� �� �� R */

	printf("������� ���������� II ����������: \n");
	int x2, y2;
	scanf_s("%d %d", &x2, &y2);

	printf("������� ������ II ����������: \n");

	int r2;
	scanf_s("%d", &r2);

	/* ������ ���������� ����� �������� ����������� d */

	int d, diff1, diff2, diff3;

	diff1 = x2 - x1;
	diff2 = y2 - y1;
	diff3 = pow(diff1, 2) + pow(diff2, 2);

	d = sqrt(diff3);

	/* ���������� ��� ������, � ������� �������� ������������ ����������� */

	if ((r1 + r2 > d) && (r1 + d > r2) && (r2 + d > r1))
		printf("���������� ������������");
	else
		if ((r1 + r2 == d) || (abs(r1 - r2) == d))
			printf("���������� ��������");
		else
			printf("���������� �� ��������");

	return 0;
}