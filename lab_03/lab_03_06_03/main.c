#include <stdio.h>
#include <stdlib.h>

#define N 10
#define CORRECT 0 // Успешное завершение
#define INCORRECT_ENTER 1 // Некорректный ввод
#define INCORRECT_VALUE 2 // Некорректные данные
#define NOT_SQUARE 3 // Не квадратная матрица

// Ввод матрицы и ее размерности
int input_rows_columns(int *n, int *m)
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
    if (*n != *m)
    {
        printf("Not a square matrix.");
        return NOT_SQUARE;
    }

    return CORRECT;
}

// Функция заполнения матрицы по спирали
int fill_matrix(int matrix[N][N], int n)
{
    int count = 1;

    for (int k = 0; k < n / 2; k++)
    {
        // левый столбец
        for (int i = k; i < n - k; i++)
        {
            matrix[i][k] = count;
            count += 1;
        }

        // нижняя строка
        for (int i = k + 1; i < n - k; i++)
        {
            matrix[n - k - 1][i] = count;
            count += 1;
        }

        // правый столбец
        for (int i = n - k - 2; i >= k; i--)
        {
            matrix[i][n - k - 1] = count;
            count += 1;
        }

        // верхняя строка
        for (int i = n - k - 2; i > k; i--)
        {
            matrix[k][i] = count;
            count += 1;
        }
    }

    if (n % 2 == 1)
        matrix[n / 2][n / 2] = count;

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
    int n, m;
    int ch;

    ch = input_rows_columns(&n, &m);
    if (ch != 0)
        return ch;

    fill_matrix(matrix, n);
    print_matrix(matrix, n, m);

    return CORRECT;
}
