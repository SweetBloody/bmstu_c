#include <stdio.h>
#include <stdlib.h>

#define N 10
#define CORRECT 0 // Успешное завершение
#define INCORRECT_ENTER 1 // Некорректный ввод
#define INCORRECT_VALUE 2 // Некорректные данные
#define EMPTY 3 // Удаление всех столбцов

// Ввод матрицы и ее размерности
int input_matrix(int matrix[N][N], int *n, int *m)
{
    int ch;

    printf("Enter the number of rows and columns:\n");
    ch = scanf("%d%d", n, m);
    if (ch != 2)
    {
        printf("Incorrect enter.\n");
        return INCORRECT_ENTER;
    }
    if (*n <= 0 || *m <= 0 || *n > 10 || *m > 10)
    {
        printf("Incorrect value.\n");
        return INCORRECT_VALUE;
    }

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            ch = scanf("%d", &matrix[i][j]);
            if (ch != 1)
            {
                printf("Incorrect enter.\n");
                return INCORRECT_ENTER;
            }
        }
    }

    return CORRECT;
}

// Ввод цифры для удаления столбцов
int input_figure(int *figure)
{
    int ch;

    printf("Enter the figure:\n");
    ch = scanf("%d", figure);
    if (ch != 1)
    {
        printf("Incorrect enter.\n");
        return INCORRECT_ENTER;
    }
    if (*figure < 0 || *figure >= 10)
    {
        printf("Incorrect value.\n");
        return INCORRECT_VALUE;
    }

    return CORRECT;
}

// Функция, определяющая входит ли цифра в число
int figure_in_number(int number, int figure)
{
    int copy_number = abs(number);

    if (number == 0 && figure == 0)
        return 1;

    while (copy_number > 0)
    {
        if (copy_number % 10 == figure)
            return 1;
        copy_number /= 10;
    }

    return 0;
}

// Изменение матрицы (удаление столбцов)
int change_matrix(int matrix[N][N], int n, int *m, int figure)
{
    int flag;
    for (int j = 0; j < *m; j++)
    {
        flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (figure_in_number(matrix[i][j], figure) == 1)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            for (int q = j; q < *m; q++)
            {
                for (int p = 0; p < n; p++)
                {
                    matrix[p][q] = matrix[p][q + 1];
                }
            }

            j -= 1;
            *m -= 1;
        }
    }

    return CORRECT;
}

// Вывод матрицы
int print_matrix(int matrix[N][N], int n, int m)
{
    printf("Result matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    return CORRECT;
}

// Основная функция
int main()
{
    int matrix[N][N];
    int n, m, figure;
    int ch;

    ch = input_matrix(matrix, &n, &m);
    if (ch != 0)
        return ch;

    ch = input_figure(&figure);
    if (ch != 0)
        return ch;

    change_matrix(matrix, n, &m, figure);
    if (m == 0)
    {
        printf("Changed array is empty.\n");
        return EMPTY;
    }
    else
        print_matrix(matrix, n, m);

    return CORRECT;
}
