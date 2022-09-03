#include <stdio.h>

#define N 10
#define CORRECT 0 // Успешное завершение
#define INCORRECT_ENTER 1 // Некорректный ввод
#define INCORRECT_VALUE 2 // Некорректные данные

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

int min_in_row(int row[], int m)
{
    int min = row[0];

    for (int i = 1; i < m; i++)
    {
        if (row[i] < min)
            min = row[i];
    }

    return min;
}

int matrix_sort(int matrix[N][N], int n, int m)
{
    int t;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (min_in_row(matrix[j], m) > min_in_row(matrix[j - 1], m))
            {
                for (int k = 0; k < m; k++)
                {
                    t = matrix[j][k];
                    matrix[j][k] = matrix[j - 1][k];
                    matrix[j - 1][k] = t;
                }
            }
        }
    }

    return  CORRECT;
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

int main()
{
    int matrix[N][N];
    int n, m;
    int ch;

    ch = input_matrix(matrix, &n, &m);
    if (ch != 0)
        return ch;

    matrix_sort(matrix, n, m);
    print_matrix(matrix, n, m);

    return CORRECT;
}
