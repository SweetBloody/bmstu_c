#include <stdio.h>
#include <stdlib.h>

#define N 10
#define CORRECT 0 // Успешное завершение
#define INCORRECT_ENTER 1 // Некорректный ввод
#define INCORRECT_VALUE 2 // Некорректные данные
#define NO_NUMBERS 3 // Нет чисел, сумма цифр которых больше 10

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

// Функция подсчета суммы цифр числа
int sum_of_figures(int number)
{
    int copy_number = abs(number), sum = 0;

    while (copy_number > 0)
    {
        sum += copy_number % 10;
        copy_number /= 10;
    }

    return sum;
}

// Функция создания массива чисел, сумма цифр которых больше 10
int create_array(int matrix[N][N], int n, int m, int array[N * N])
{
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sum_of_figures(matrix[i][j]) > 10)
            {
                array[len] = matrix[i][j];
                len += 1;
            }
        }
    }

    return len;
}

// Функция сдвига элементов массива на 3 позиции влево
int move_array(int array[N * N], int n)
{
    int a0;

    for (int k = 0; k < 3; k++)
    {
        a0 = array[0];

        for (int i = 0; i < n - 1; i++)
            array[i] = array[i + 1];

        array[n - 1] = a0;
    }

    return CORRECT;
}

// Функция подстановки чисел из массива в матрицу
int array_to_matrix(int matrix[N][N], int n, int m, int array[N * N])
{
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sum_of_figures(matrix[i][j]) > 10)
            {
                matrix[i][j] = array[index];
                index += 1;
            }
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
    int matrix[N][N], array[N * N];
    int n, m, len;
    int ch;

    ch = input_matrix(matrix, &n, &m);
    if (ch != 0)
        return ch;

    len = create_array(matrix, n, m, array);
    if (len == 0)
    {
        printf("There are no number which figure sum is more than 10.");
        return NO_NUMBERS;
    }
    move_array(array, len);
    array_to_matrix(matrix, n, m, array);
    print_matrix(matrix, n, m);

    return CORRECT;
}
