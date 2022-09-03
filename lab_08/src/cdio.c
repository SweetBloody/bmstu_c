#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "cdio.h"

// Чтение размерности матрицы из файла
int input_matrix_size(char *file_name, int *n, int *m)
{
    int ch;
    FILE *file = fopen(file_name, "r");

    ch = fscanf(file, "%d %d", n, m);

    if (ch != 2 || *n <= 0 || *m <= 0)
    {
        fclose(file);
        return INCORRECT_MATRIX_SIZE;
    }

    fclose(file);

    return OK;
}

// Создание матрицы
double **create_matrix(int n, int m)
{
    double **pstr, *data;

    pstr = malloc(n * sizeof(double*));

    if (!pstr)
        return NULL;

    data = malloc(n * m * sizeof(double));

    if (!data)
    {
        free(pstr);
        return NULL;
    }

    for (int i = 0; i < n; i++)
        pstr[i] = data + i * m;

    return pstr;
}

// Освобождение памяти матрицы
void free_matrix(double **matrix, double *start_string)
{
    free(start_string);

    free(matrix);
}

// Перевод указателя на новую строку
void ptr_to_next_str(FILE *file)
{
    char tmp = '0';

    while (tmp != '\n')
        fscanf(file, "%c", &tmp);
}

// Заполнение матрицы
int input_matrix(char *file_name, double **matrix, int n, int m)
{
    int ch;
    double number;
    FILE *file = fopen(file_name, "r");

    ptr_to_next_str(file);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            ch = fscanf(file, "%lf", &number);

            if (ch != 1)
            {
                fclose(file);
                return INCORRECT_INPUT;
            }

            matrix[i][j] = number;
        }

    fclose(file);

    return OK;
}

// Вывод матрицы в файл
void print_matrix_to_file(char *file_name, double **matrix, int n, int m)
{
    FILE *file = fopen(file_name, "w");

    fprintf(file, "%d %d\n", n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
            fprintf(file, "%f ", matrix[i][j]);

        fprintf(file, "%f\n", matrix[i][m - 1]);
    }

    fclose(file);
}

// Создание и заполнение массива решения СЛАУ
int *create_array(int rows)
{
    int *array = NULL;

    array = malloc(rows * sizeof(int));

    if (array == NULL)
        return NULL;

    for (int i = 0; i < rows; i++)
        array[i] = i;

    return array;
}

// Вывод решения СЛАУ в файл
void print_array_to_file(char *file_name, double **matrix, int columns, int *array, int length)
{
    FILE *file = fopen(file_name, "w");
    int index = 0;

    fprintf(file, "%d 1\n", length);

    while (index != length)
    {
        for (int i = 0; i < length; i++)
            if (array[i] == index)
            {
                fprintf(file, "%f\n", matrix[i][columns - 1]);
                index += 1;
            }
    }

    fclose(file);
}

// Вывод сообщений об ошибках
void print_errors(int ch)
{
    if (ch == INCORRECT_ARGS)
        printf("INCORRECT_ARGS\n");

    if (ch == NO_DATA)
        printf("NO_DATA\n");

    if (ch == INCORRECT_INPUT)
        printf("INCORRECT_INPUT\n");

    if (ch == FILE_OPEN_ERR)
        printf("FILE_OPEN_ERR\n");

    if (ch == FILE_CLOSE_ERR)
        printf("FILE_CLOSE_ERR\n");

    if (ch == FILE_ERR)
        printf("FILE_ERR\n");

    if (ch == MEMORY_GET_ERROR)
        printf("MEMORY_GET_ERROR\n");

    if (ch == INCORRECT_MATRIX_SIZE)
        printf("INCORRECT_MATRIX_SIZE\n");

    if (ch == IMPOSSIBLE_TO_ADD)
        printf("IMPOSSIBLE_TO_ADD\n");

    if (ch == IMPOSSIBLE_TO_MULTIPLE)
        printf("IMPOSSIBLE_TO_MULTIPLE\n");

    if (ch == GAUSS_ERROR)
        printf("GAUSS_ERROR\n");
}