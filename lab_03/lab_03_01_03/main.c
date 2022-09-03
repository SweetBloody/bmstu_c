#include <stdio.h>

#define N 10
#define CORRECT 0 // Успешное завершение
#define INCORRECT_ENTER 1 // Некорректный ввод
#define INCORRECT_VALUE 2 // Некорректные данные

// Функция ввода матрицы и ее размерности
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

// Функция проверки строки на монотонность
int is_monotone(int *pa, int m)
{
    int flag = 1;
    int i = 0;

    while (*pa == *(pa + 1) && i < m - 2)
    {
        pa += 1;
        i += 1;
    }

    if (i == m - 1)
        return 1;
    else
    {
        if (*pa < *(pa + 1))
        {
            for (int k = i; k < m - 1; k++)
            {
                if (*(pa + 1) < *pa)
                {
                    flag = 0;
                    break;
                }
                pa += 1;
            }
        }
        else
        {
            for (int k = i; k < m - 1; k++)
            {
                if (*(pa + 1) > *pa)
                {
                    flag = 0;
                    break;
                }
                pa += 1;
            }
        }
    }
    return flag;
}

// Функция формирования массива
int result_array(int matrix[N][N], int n, int m, int array[N])
{
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
            array[i] = 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
            array[i] = is_monotone(matrix[i], m);
    }

    return CORRECT;
}

// Функция вывода массива
int print_array(int array[N], int n)
{
    printf("Result array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return CORRECT;
}

// Основная функция
int main()
{
    int matrix[N][N];
    int array[N];
    int n, m;
    int ch;

    ch = input_matrix(matrix, &n, &m);
    if (ch != 0)
        return ch;

    result_array(matrix, n, m, array);
    print_array(array, n);

    return CORRECT;
}


