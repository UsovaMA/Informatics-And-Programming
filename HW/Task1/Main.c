#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	int x1, y1; //������ ������
	int x2, y2; //������ ������
	int num; //����� ������
	printf("������� ���������� ������ ������ X � Y (����� ������): ");
	scanf_s("%d %d", &x1, &y1);
	printf("\n������� ���������� ������ ������ X � Y (����� ������): ");
	scanf_s("%d %d", &x2, &y2);
	if (x1 <= 8 && x2 <= 8 && y1 <= 8 && y2 <= 8)
	{
		printf("����� ������� ����� ������?\n 1. ������\n 2. �����\n 3. �����\n 4. ����\n 5. ����\n ������� �����: ");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
			if ((x1 - x2 <= 1 && x1 - x2 >= -1) && (y1 - y2 <= 1 && y1 - y2 >= -1) && num == 1)
			{
				printf("������ ���������!");
				break;
			}
		case 3:
			if ((x1 == x2 || y1 == y2) && num == 3)
			{
				printf("����� ����������!");
				break;
			}
		case 4:
			if (  (  ((x1 + y1) % 2 == 0 && (x2 + y2) % 2 == 0) || ((x1 + y1) % 2 == 1 && (x2 + y2) % 2 == 1)  )  && num == 4)
			{
				printf("���� ���������!");
				break;
			}
		case 5:
			if ((((x1 + y1 + 1 == x2 + y2) || (x1 + y1 - 1 == x2 + y2)) || ((x1 + y1 + 3 == x2 + y2) || (x1 + y1 - 3 == x2 + y2))) && num == 5)
			{
				printf("���� ���������!");
				break;
			}
		case 2:
			if (((x1 - x2 <= 1 && x1 - x2 >= -1) && (y1 - y2 <= 1 && y1 - y2 >= -1) || (x1 == x2 || y1 == y2) || (((x1 + y1) % 2 == 0 && (x2 + y2) % 2 == 0) || ((x1 + y1) % 2 == 1 && (x2 + y2) % 2 == 1))) && num == 2)
			{
				printf("����� ���������!");
				break;
			}
		default:
		{
			printf("��������� ���� ������ �� ����� ������� ���.\n��� ������ ��������� �����, ������� ����� �������: \n");
			switch (num)
			{
			case 1:
				if ((x1 - x2 <= 1 && x1 - x2 >= -1) && (y1 - y2 <= 1 && y1 - y2 >= -1))
				{
					printf("* ������\n");
				}
			case 3:
				if ((x1 == x2 || y1 == y2))
				{
					printf("* �����\n");
				}
			case 4:
				if ((   ((x1 + y1) % 2 == 0 && (x2 + y2) % 2 == 0) || ((x1 + y1) % 2 == 1 && (x2 + y2) % 2 == 1)   ))
				{
					printf("* ����\n");
				}
			case 5:
				if ((((x1 + y1 + 1 == x2 + y2) || (x1 + y1 - 1 == x2 + y2)) || ((x1 + y1 + 3 == x2 + y2) || (x1 + y1 - 3 == x2 + y2))) && num == 5)
				{
					printf("* ����\n");
				}
			case 2:
				if ((x1 - x2 <= 1 && x1 - x2 >= -1) && (y1 - y2 <= 1 && y1 - y2 >= -1) || (x1 == x2 || y1 == y2) || (((x1 + y1) % 2 == 0 && (x2 + y2) % 2 == 0) || ((x1 + y1) % 2 == 1 && (x2 + y2) % 2 == 1)))
				{
					printf("* �����\n");
					break;
				}
			default:
				{
				printf(" �� ���� ������ �� ����� ��� �������!");
				}
			}
		}
		}
	}
	else
	{
		printf("\n��������� ����� ������� 8x8 ������, �������� ������ ������");
	}
	return 0;
}