#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");

	int coin; // ���� ������
	int k = 0;// ���-�� �����
	printf("���� ������: ");
	scanf_s("%d", &coin);
	while (coin > 0)
	{
		if (coin - 25 >= 0)
		{
			coin -= 25;
			k++;
		}
		else if (coin - 10 >= 0)
		{
			coin -= 10;
			k++;
		}
		else if (coin - 5 >= 0)
		{
			coin -= 5;
			k++;
		}
		else if (coin - 1 >= 0)
		{
			coin -= 1;
			k++;
		}
	}
	printf("\n����������� ���������� �����: %d", k);
}