#include<locale.h>
#include<stdio.h>
#include<math.h>
#define pi 3.14

void main()
{
	setlocale(LC_ALL, "RUS");
	int vst, osn, Str, strn1, strn2, Sprm, R;
	float So;
	printf("������� ������ � ��������� ������������ : ");
	scanf_s("%d %d", &vst, &osn);
	Str = (vst * osn) / 2;
	printf("������� ������� �������������� : ");
	scanf_s("%d %d", &strn1, &strn2);
	Sprm = strn1 * strn2;
	printf("������� ������ ���������� : ");
	scanf_s("%d", &R);
	So = pi * R * R * 0.5;
	printf(" ������� ������������ = %d \n", Str);
	printf(" ������� �������������� = %d \n", Sprm);
	printf(" ������� ���������� = %f \n", So);

	return 0;
}









 

