#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int main() 
{
    setlocale(LC_ALL, "rus");
    int rnd, otv, mode, cnt = 0;      
    char znak;   
    printf("�������� ����� (1 ��� 2) : ");
    scanf_s("%d", &mode);

    switch (mode)
    {
    case 1:
    {
        srand(time(0));
        rnd = rand() % 1000;

        do
        {
            printf("������� ����� ���������� ���������� (�� 1 �� 1000) : \n");
            scanf_s("%d", &otv);

            if (rnd == otv)
            {
                printf(" �������\n");
                cnt++;
                printf("���� %d �������\n", cnt);
            }
            else
            {
                if (rnd < otv)
                {
                    printf(" ������ \n");
                    cnt++;
                }
                else if (rnd > otv)
                {
                 printf(" ������ \n");
                 cnt++;
                }
                
            }
        } while (rnd != otv);
    } break;

    case 2:
    {
        printf("��������� ����� (�� 1 �� 1000), ���� ����� ���������� ������� ����� ������ ������� > ���� ������ < � = ���� ����� ������ \n");
        do
        {
            int rnd2;
            srand(time(0));
            rnd2 = rand() % 1000;
            printf(" ����� %d ? ", rnd2);
            scanf_s("%ch", &znak);

            if (znak == '=')
            {
                printf(" ������� ! ");
                cnt++;
                printf("���� �������: %d", cnt);
            }
            else
            {
                if (znak == '>')
                {
                   // ???
                    cnt++;
                }
                if (znak == '<')
                {
                   // ???
                    cnt++;
                }
            }

        } while (znak != '=');
    } break;

    default:
    {
        printf(" �������� ����� 1 ��� 2 ! ");
    }
    break;
    }
    return 0;
}  