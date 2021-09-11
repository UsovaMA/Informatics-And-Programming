#include <stdio.h>
#include <locale.h>
#include <math.h>

/*������ ��������� */
int main()
{
	/*������ ������� ���� � ������*/
	setlocale(LC_ALL, "Russian");

	/*������ ����������, ������� ����� � ������*/

	int doorWood, shelfDsp, h, d,
		w, thickness3 = 1;

	float backCBdvp, sideCBdsp, downCBdsp,
		thickness1 = 0.5, thickness2 = 1.5;


	int flag = 0;
	/*������ ������������ ���� ������ � ������, �������� ������������ ���������*/

	do {
		printf("Enter width and height (width: 180-220; height:	80-120)(through a space): ");
		scanf_s("%d %d", &h, &w);
		if ((h > 179 && h < 221) && (w > 79) && (w < 121))
			flag = 1;
		else
			printf("Wrong Range!\n");
	} while (flag != 1);

	/*������ ������������ ���� �������, �������� ������������ ���������*/

	do {
		printf("Enter depth: ");
		scanf_s("%d", &d);
		if (d > 49 && d < 90)
			flag = 1;
		else
			printf("Wrong Range!\n");
	} while (flag != 1);

	/*������ ������������ ������ ��������� ���, ��� � ������*/

	int dsp, dvp, wood;

	printf("�nter the density of Chipboard Fiberboard and Wood: ");
	scanf_s("%d %d %d", &dsp, &dvp, &wood);

	/*������� ����� ���� ������ �����*/

	backCBdvp = (h * w * thickness1) / 1000000;
	sideCBdsp = (h * d * thickness2) / 1000000;
	downCBdsp = (w * d * thickness2) / 1000000;
	doorWood = (h * w * thickness3) / 1000000;

	/*��� ��� �� ���� ������� ����� - ���� ������ �� ������������: */

	float thickness4;

	printf("input shelf's thickness: ");
	scanf_s("%f", &thickness4);

	shelfDsp = (d * w * thickness4) / 1000000;

	/*������ ���������� ��� ���������� �����*/

	float shelfAmount;

	shelfAmount = h / 40;

	/*������� ����� �����: */

	float m;

	m = (backCBdvp * dvp) + ((sideCBdsp * 2) * dsp) + ((downCBdsp * 2) * dsp) + ((doorWood * 2) * wood) + (floor(shelfAmount) * shelfDsp * wood);

	printf("Cupboard's weight - %.1f", m);

	return 0;
}