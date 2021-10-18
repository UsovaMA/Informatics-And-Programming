// Copyright 2021 Marina Usova

/*
* ������� 1 (1 ����)
* ��������� ������ ������� N ���������� ���������� � ��������� �� -A �� A �
* ��������� ����������� ����� ������ �� K ��������� � ����������.
* ���������. ���������� ������ ������ �������� ������.
*
* ������� 2 (3 �����)
* ������ ��� � ���� �������� ��������� ������������. � ������� ����������� ����
* ���� ���������� ����� � ���������� � ��� ������ (���������� ��� ���������).
* ���� ���� ����� �� ����������� ����������� ��������� � ���� ���� ����� �,
* ���������� ��������� ����, � ����� ����������� �� ������ ����������� ���������.

* ������� 3 (5 ������)
* ��������� ���������� ���������� ������ N �������. ������ ������� �������
* ���������� � ���, � ����� ����������� ����� �� ������. ����� ����� ����������
* ��� ������ ���� ���������������� � ������ ���� ������ ������:
*   - �������� �� ����������,
*   - ���������� ������� ����, ��� � ��� ������.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main() {
  int task = 0, size = 0, temp_1 = 0, temp_2 = 0;
  int* values = NULL;

  // var 1
  int board = 0, shift = 0;
  int prev = 0, cur = 0;
  // var 2
  int exam_scores_1 = 0, exam_scores_2 = 0, exam_scores_3 = 0, admission_plan = 0, passing_score = 0;
  int* IDs = NULL;
  // var 3
  int** acuaintance = NULL;
  int mistake_in_data = 0, not_all = 1;

  srand(time(0));

  while (1) {
    // INPUT BLOCK

    // ����� �������� ������� ����������� ������
    printf("Choose number of variant:\n  1. easy (1 point),\n  2. middle (3 points),\n  3. hard (5 points)\n  0. exit\n> ");
    scanf_s("%d", &task);

    if (task == 0) break;

    // ���� ������ ��� ������������ ������� � ����������� �������� �������
    switch (task) {
    case 1:
      printf("Input size\n> ");
      scanf_s("%d", &size);
      printf("Input board of values\n> ");
      scanf_s("%d", &board);
      printf("Input shift\n> ");
      scanf_s("%d", &shift);

      // ������ 1 ���������� ������� - ���������� ���������� ������� �� ��������� ���������
      values = (int*)malloc(size * sizeof(int));
      for (int i = 0; i < size; i++)
        // �� -board �� board
        values[i] = rand() % (board * 2 + 1) - board;

      printf("Generate massive: ");
      for (int i = 0; i < size; i++)
        printf("%d ", values[i]);
      printf("\n");
      break;
    case 2:
      printf("Input number of abiturience\n");
      printf("> ");
      scanf_s("%d", &size);
      printf("Input admission plan\n");
      printf("> ");
      scanf_s("%d", &admission_plan);

      // ������ 2 ���������� ������� (values) - ���������� ������� ������������ �� ������-�� ������� ����������
      // ������ 3 ���������� ������� (IDs) - ���������� ������������� ������� (1, 2, 3, 4, ...)
      IDs = (int*)malloc(size * sizeof(int));
      values = (int*)malloc(size * sizeof(int));
      printf("Input exams scores for students by ID (between spaces)\n");
      for (int i = 0; i < size; i++) {
        printf("ID:%d> ", i + 1);
        scanf_s("%d %d %d", &exam_scores_1, &exam_scores_2, &exam_scores_3);
        values[i] = exam_scores_1 + exam_scores_2 + exam_scores_3;
        IDs[i] = i + 1;
      }
      break;
    case 3:
      printf("Input number of population\n");
      printf("> ");
      scanf_s("%d", &size);

      values = (int*)malloc(size * sizeof(int));
      IDs = (int*)malloc(size * sizeof(int));

      // ��������� ������ ��� ��������� ������ � ����������� ����� ������� ������
      /* ������ acuaintance ���, ��������, 5 ������� ���������� �������� ���:
       * 0 0 0 0 0
       * 0 0 0 0 0
       * 0 0 0 0 0
       * 0 0 0 0 0
       * 0 0 0 0 0
       */
      acuaintance = (int**)malloc(size * sizeof(int*));
      for (int i = 0; i < size; i++) {
        acuaintance[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
          acuaintance[i][j] = 0;
        }
      }

      // ������ 4 ���������� ������� - ������ ���� (� ����������)
      printf("Input number of friends for resident num.\n");
      for (int i = 0; i < size; i++) {
        printf("%d> ", i + 1);
        scanf_s("%d", &values[i]);
        IDs[i] = i + 1;
      }
      break;
    default:
      break;
    }

    // ACTIONS BLOCK (algorithms)
    switch (task) {
    case 1:
      // ����������� ����� ������
      for (int j = 0; j < shift; j++) {
        prev = values[0];
        for (int i = 1; i < size; i++) {
          cur = values[i];
          values[i] = prev;
          prev = cur;

        }
        values[0] = prev;
      }
      // ��������
      for (int i = 0; i < size / 2; i++) {
        temp_1 = values[i];
        values[i] = values[size - i - 1];
        values[size - i - 1] = temp_1;
      }
      break;
    case 2:
      // ���������� �� ����������� � ������������ ��������
      for (int j = 0; j < size; j++) {
        int all_right = 1;
        for (int i = 0; i < size; i++) {
          // ���� ����������� �������� � ������������ ������� - ������ �� �������
          // ������ ������� � �� �������, ����� �������� ������� ���������
          if (values[i] < values[i + 1]) {
            temp_1 = values[i];
            temp_2 = IDs[i];
            values[i] = values[i + 1];
            IDs[i] = IDs[i + 1];
            values[i + 1] = temp_1;
            IDs[i + 1] = temp_2;
            all_right = 0;
          }
        }
        // ���� �� ����� ������������ �� �������� �� ������� - ���������
        if (all_right) break;
      }
      break;
    case 3:
      // ������� �������� �� ������� ������ � ������� ������
      mistake_in_data = 0;
      not_all = 1;
      for (int i = 0; i < size; i++) {
        if (values[i] < 0 || values[i] >= size) {
          mistake_in_data = 1;
          break;
        }
      }
      // ���� �� �� ��������� ������ � ������ ��� �� ���������� ��� �������� - ��������
      while (!mistake_in_data || not_all) {
        // ���������� �� ����������� � ������������ ��������
        /* ������ �� ������������ - 5 : 2 4 3 1 2
         * �� ������ ����������:
         * values: 2 4 3 1 2
         * IDs:    1 2 3 4 5
         * ����� ������ ����������
         * values: 4 3 2 2 1
         * IDs:    2 3 1 5 4
         */
        for (int j = 0; j < size; j++) {
          int all_right = 1;
          for (int i = 0; i < size; i++) {
            if (values[i] < values[i + 1]) {
              temp_1 = values[i];
              temp_2 = IDs[i];
              values[i] = values[i + 1];
              IDs[i] = IDs[i + 1];
              values[i + 1] = temp_1;
              IDs[i + 1] = temp_2;
              all_right = 0;
            }
          }
          if (all_right) break;
        }
        // ���� ���������� ��������� 0, �� �� ��� ���������� �������� - ��������� ����
        if (values[0] == 0) {
          not_all = 0;
          break;
        }
        // ����� ������ ������������� �������� �������� (� ���� ����� IDs[0])
        // ��������, ��� �� ������ � values[0] ������
        for (int i = 1; i < values[0] + 1; i++) {
          // IDs[0] ������ � IDs[i]
          acuaintance[IDs[0] - 1][IDs[i] - 1] = 1;
          // ����� ��������, ��� IDs[i] ������ � IDs[0]
          acuaintance[IDs[i] - 1][IDs[0] - 1] = 1;
          // �� �������� ��� IDs[i] ���� ���������� - �������� ����� ��� ������
          values[i] -= 1;
          // ���� ����� � ������������� ����� - ������ ������������ (���-�� ������)
          if (values[i] < 0) {
            mistake_in_data = 1;
            break;
          }
        }
        // ������ "�����������" �������� �� ����������� � ������� ��� ����� -1, 
        // ����� ��� �������� ��� �� ������
        values[0] = -1;

        /* ��������� ��� ������ � 5 : 2 4 3 1 2
         *
         * 1 ��������
         * �� ��������, ��� � �������� ����� 2 ������ ����� ������ (4) � �������� ��
         * (�������� ����� � ���� �������� ������������ ���� ��������� ���������)
         * values: 4 3 2 2 1
         * IDs:    2 3 1 5 4
         * ������� �2 - 3 1 5 4
         * 0 1 0 0 0
         * 0 0 0 0 0
         * 0 1 0 0 0
         * 0 1 0 0 0
         * 0 1 0 0 0
         * � ���������� � ���:
         * 0 1 0 0 0
         * 1 0 1 1 1
         * 0 1 0 0 0
         * 0 1 0 0 0
         * 0 1 0 0 0
         * values: -1 2 1 1 0
         * IDs:     2 3 1 5 4
         *
         * 2 ��������
         * values: 2 1 1 0 -1
         * IDs:    3 1 5 4  2
         * ������� �3 - 1 5
         * 0 1 1 0 0
         * 1 0 1 1 1
         * 1 1 0 0 1
         * 0 1 0 0 0
         * 0 1 1 0 0
         * values: -1 0 0 0 -1
         * IDs:     3 1 5 4  2
         *
         * 3 ��������
         * values: 0 0 0 -1 -1
         * IDs:    1 5 4  3  2
         * ������� �1 - .
         * values[0] == 0 - break
         *
         * ������������� ��������� ��������������� �� ������� ���������
         * 0 1 1 0 0
         * 1 0 1 1 1
         * 1 1 0 0 1
         * 0 1 0 0 0
         * 0 1 1 0 0
         *
         * 1: 2 3 (� ������ ������� ������� �� ������ � ������� ������)
         * 2: 1 3 4 5
         * 3: 1 2 5
         * 4: 2
         * 5: 2 3
         *
         */
      }
      break;
    default:
      break;
    }

    // OUTPUT
    switch (task) {
    case 1:
      printf("Output massive:   ");
      for (int i = 0; i < size; i++)
        printf("%d ", values[i]);
      printf("\n");
      break;
    case 2:
      printf("Passing score: %d\n", values[admission_plan - 1]);
      printf("Rate : Student ID : Summ Of Score\n");
      for (int i = 0; i < size; i++) {
        if (i == admission_plan)
          printf("================================\nNOT ENTER IN UNN\n");
        printf("%d : stud%d : %d\n", i + 1, IDs[i], values[i]);
      }
      free(IDs);
      break;
    case 3:
      if (mistake_in_data)
        printf("\n !!! OPS is mistake in input data\n");
      else {
        printf("Human: his friends\n");
        for (int i = 0; i < size; i++) {
          printf("%d: ", i + 1);
          for (int j = 0; j < size; j++) {
            if (acuaintance[i][j] != 0) printf("%d ", j + 1);
          }
          printf("\n");
        }
      }
      free(IDs);
      for (int i = 0; i < size; i++) free(acuaintance[i]);
      free(acuaintance);
      break;
    default:
      break;
    }

    // �� �������� ������� ���������� ������
    free(values);
  }

  return 0;
}
