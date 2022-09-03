#include <stdio.h>

#define N 10
#define CORRECT 0 // Успешное завершение
#define INCORRECT_ENTER 1 // Некорректный ввод
#define INCORRECT_VALUE 2 // Некорректные данные
#define NOT_SQUARE 3 // Не квадратная матрица

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
    if (*n != *m)
    {
        printf("Not a square matrix.");
        return NOT_SQUARE;
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

// Функция перестановки элементов
int change_matrix(int matrix[N][N], int n, int m)
{
    int t;

    for (int j = 0; j < m / 2; j++)
    {
        for (int i = j; i < n - j; i++)
        {
            t = matrix[i][j];
            matrix[i][j] = matrix[i][m - j - 1];
            matrix[i][m -j - 1] = t;
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
    int n, m;
    int ch;

    ch = input_matrix(matrix, &n, &m);
    if (ch != 0)
        return ch;

    change_matrix(matrix, n, m);
    print_matrix(matrix, n, m);

    return CORRECT;
}
