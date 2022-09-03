#include <math.h>
#include "const.h"
#include "process.h"

#define EPS 0.00001

// Проверка на возможность сложения матриц
int addition_check(int n1, int m1, int n2, int m2)
{
    if (n1 != n2 || m1 != m2)
        return IMPOSSIBLE_TO_ADD;

    return OK;
}

// Сложение матриц
void matrix_addition(double **matrix_1, double **matrix_2, double **matrix_res, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix_res[i][j] = matrix_1[i][j] + matrix_2[i][j];
}

// Проверка на возможность умножения матриц
int multiply_check(int m1, int n2)
{
    if (m1 != n2)
        return IMPOSSIBLE_TO_MULTIPLE;

    return OK;
}

// Умножение матриц
void matrix_multiply(double **matrix_1, int row_1, int column_1, double **matrix_2, int column_2, double **matrix_res)
{
    double sum = 0;

    for (int i = 0; i < row_1; i++)
    {
        for (int j = 0; j < column_2; j++)
        {
            sum = 0;

            for (int k = 0; k < column_1; k++)
                sum += matrix_1[i][k] * matrix_2[k][j];

            matrix_res[i][j] = sum;
        }
    }
}

// Проверка на наличие нулевой строки
int matrix_null_row_check(double **matrix, int rows, int columns)
{
    int flag;

    for (int i = 0; i < rows; i++)
    {
        flag = 0;

        for (int j = 0; j < columns - 1; j++)
            if (fabs(matrix[i][j]) > EPS)
                flag = 1;

        if (flag == 0)
            return GAUSS_ERROR;
    }

    return OK;
}

// Проверка на наличие нулевого столбца
int matrix_null_col_check(double **matrix, int rows, int columns)
{
    int flag;

    for (int j = 0; j < columns - 1; j++)
    {
        flag = 0;

        for (int i = 0; i < rows; i++)
            if (fabs(matrix[i][j]) > EPS)
                flag = 1;

        if (flag == 0)
            return GAUSS_ERROR;
    }

    return OK;
}

// Метод Гаусса
int gauss(double **matrix, int rows, int columns, int *result_array)
{
    int max_i, max_j, tmp_res, ch;
    double max, tmp, nul, *tmp_str;

    // Прямой ход
    for (int k = 0; k < rows; k++)
    {
        // Нахождение максимального элемента в матрице
        max = fabs(matrix[k][k]);
        max_i = k;
        max_j = k;

        for (int i = k; i < rows; i++)
        {
            for (int j = k; j < columns - 1; j++)
            {
                if (fabs(matrix[i][j]) > max)
                {
                    max = fabs(matrix[i][j]);
                    max_i = i;
                    max_j = j;
                }
            }
        }

        // Ставим строку с максимальным элементом в начало матрицы
        tmp_str = matrix[k];
        matrix[k] = matrix[max_i];
        matrix[max_i] = tmp_str;

        // Ставим столбец с максимальным элементом в начало матрицы
        for (int i = 0; i < columns - 1; i++)
        {
            tmp = matrix[i][k];
            matrix[i][k] = matrix[i][max_j];
            matrix[i][max_j] = tmp;
        }

        tmp_res = result_array[k];
        result_array[k] = result_array[max_j];
        result_array[max_j] = tmp_res;

        // Нормируем строки
        for (int i = k; i < rows; i++)
            for (int j = columns - 1; j >= k; j--)
                if (fabs(matrix[i][k]) > EPS)
                    matrix[i][j] = matrix[i][j] / matrix[i][k];

        // Вычитаем из каждой строки ведущую строку матрицы
        for (int i = k + 1; i < rows; i++)
        {
            nul = matrix[i][k];

            for (int j = k; j < columns; j++)
                if (fabs(nul) > EPS)
                    matrix[i][j] = matrix[i][j] - matrix[k][j];
        }

        ch = matrix_null_row_check(matrix, rows, columns);

        if (ch != OK)
            return ch;
    }

    // Обратный ход
    for (int k = 0; k < rows - 1; k++)
    {
        for (int i = rows - 2 - k; i >= 0; i--)
        {
            tmp = matrix[i][columns - k - 2];

            for (int j = 0; j < columns; j++)
                matrix[i][j] = matrix[i][j] - matrix[rows - 1 - k][j] * tmp;
        }
    }

    return OK;
}

// Проверка на равенство матриц
int matrix_eq(double **matrix_1, double **matrix_2, int rows, int columns)
{
    int flag = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if ((matrix_1[i][j] - matrix_2[i][j]) > EPS)
            {
                flag = 1;
                break;
            }

    return flag;
}

// Проверка решения СЛАУ методом Гаусса
int gauss_res_check(double **matrix, int rows, int columns, int *result_array, double *result)
{
    int index = 0;

    while (index != rows)
    {
        for (int i = 0; i < rows; i++)
            if (result_array[i] == index)
            {
                if (fabs(result[index] - matrix[i][columns - 1]) > EPS)
                    return 1;
                index += 1;
            }
    }

    return 0;
}