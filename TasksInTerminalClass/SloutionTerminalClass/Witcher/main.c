/*���� ��������, ��� ������� �������� ������� ����� �������, ������ ��� ������ ��������� ��������,
� ���� �� ������� �� ��������� ������, �� ��������� ������ �������� ������.
� ���� �������� ���������� ������ � ���������� 1, 5, 10, 25.
�������� ���������, ������� ���������� ����� ����������� ���������� �������� ����� ����� ��������� ��������.
������ ������� ������ �� ���� ��������� �������� ���� ����������� �����, ���� �� ������ ��������.
������ �������� ������ ��������� ������ ������� ���������� ��������� ���������� �������� ����� ��� ������.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "russian");
	printf("������ ������� � ������� ������ ��������, �������� �� �����, ��� ������ ����� ���������� ���������� �����\n");

	int a = 25, b = 10, c = 5, d = 1;		// ������� �������.
	int min = 0;
	int cash;								// ���������� �������.

	printf("�������� ��������� �������� ������� (�����):");
	scanf_s("%d", &cash);

	while (cash > 0) {
		while (cash >= a) {
			cash = cash - a;
			min += 1;
		}

		while (cash >= b) {
			cash = cash - b;
			min += 1;

		}
		while (cash >= c) {
			cash = cash - c;
			min += 1;
		}

		while (cash >= d) {
			cash = cash - d;
			min += 1;
		}

	}

	printf("����� ������� �������� � �������: %d �����\n ", min);
	return 0;
}