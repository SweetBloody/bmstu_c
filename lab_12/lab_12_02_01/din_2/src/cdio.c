#include <stdio.h>
#include "cdio.h"
#include "const.h"

// Считает количество чисел в файле
int count_numbers_amount(char *file_name, int *amount)
{
    int ch, tmp_number = 0;
    FILE *f = fopen(file_name, "r");

    *amount = 0;

    ch = fscanf(f, "%d", &tmp_number);

    if (ch != 1)
    {
        fclose(f);
        return EMPTY_FILE;
    }

    *amount += 1;

    while (!feof(f))
    {
        ch = fscanf(f, "%d", &tmp_number);

        if (ch != 1 && ch != EOF)
        {
            fclose(f);
            return INCORRECT_INPUT;
        }
        else if (ch == 1)
            *amount += 1;
    }

    fclose(f);

    return OK;
}

// Создание и заполнение массива
int create_array(char *file_name, int **array, int numbers_amount)
{
    FILE *f = fopen(file_name, "r");
    int *start;

    start = *array;

    while (start < *array + numbers_amount)
    {
        fscanf(f, "%d", start);
        start += 1;
    }

    fclose(f);

    return OK;
}

// Вывод чисел из массива в файл
void print_array_to_file(char *file_name, int *array_st, int *array_end)
{
    FILE *f = fopen(file_name, "w");

    while (array_st < array_end)
    {
        fprintf(f, "%d ", *array_st);
        array_st += 1;
    }

    fclose(f);
}

// Вывод сообщений об ошибках
void print_errors(int ch)
{
    if (ch == INCORRECT_ARGS)
        printf("INCORRECT_ARGS\n");

    if (ch == EMPTY_FILE)
        printf("EMPTY_FILE\n");

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

    if (ch == GOT_EMPTY_ARRAY)
        printf("GOT_EMPTY_ARRAY\n");

    if (ch == LOAD_LIB_ERR)
        printf("LOAD_LIB_ERR\n");

    if (ch == LOAD_FUNC_ERR)
        printf("LOAD_FUNC_ERR\n");

}
