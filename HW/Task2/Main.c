#include <stdio.h>
#include <locale.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int r, k, flag = 0, num, pop = 0; // ����� ������, ������, ���� ����� � �������
	printf("\t\t<<<--- ������ ����� --->>> (�� 1 �� 1000)\n\n");
	printf("��� ����� ������? (�������� ����� �� ������)\n 1. �������� �����\n 2. �������� �����\n ��� �����: ");
	scanf_s("%d", &r);

	if (r == 1)
	{
		srand(time(0));
		k = rand() % 1000 + 1;
		printf(" <|  �������� ����!  |>\n");
		while (flag != 1)
		{
			printf("\n������� �����: ");
			scanf_s("%d", &num);
			if (num > k)
			{
				printf("���������� ����� ������\n");
				pop++;
			}
			else if (num < k)
			{
				printf("���������� ����� ������\n");
				pop++;
			}
			else
			{
				printf("�� �������!\n���������� �������: %d\n\n", pop);
				flag = 1;
			}
		}
	}
	else if (r == 2)
	{
		char srav[1];
		int x1 = 1, x2 = 1000, mid = (x2 + x1) / 2;
		printf("������� ����� (�� 1 �� 1000): ");
		scanf_s("%d", &num);
		printf("\n <|  �������� ����!  |>\n\n");
		while (flag != 1)
		{
			printf("\n���� �����: %d ?\n�������� ���� ��������� (< > =):  ",mid);
			char srav = getche();
			if (srav == 62)
			{
				x1 = mid;
				printf("\n%d\n", x1);
				pop++;
				mid = (x2 + x1) / 2;
			}
			else if (srav == 60)
			{
				x2 = mid;
				printf("\n%d", x1);
				pop++;
				mid = (x2 + x1) / 2;
			}
			else if (srav == 61)
			{
				printf("\n\n���� ���������� �����: %d\n", mid); 
				printf("���������� �������: %d\n", pop);
				flag = 1;
			}
			else
			{
				printf("\n������ �������� ����!\n");
			}
		}
	}
	else
	{
		printf("�������� ����� �� ������������!");
	}
	return 0;
}