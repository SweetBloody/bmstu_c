#include <stdio.h>
#include "cdio.h"
#include "const.h"

// Считает количество чисел в файле
ARR_DLL int ARR_DECL count_numbers_amount(char *file_name, int *amount)
{
    int ch, tmp_number = 0;
    FILE *f = fopen(file_name, "r");

    *amount = 0;

    ch = fscanf(f, "%d", &tmp_number);

    if (ch != 1)
    {
        fclose(f);
        return NO_DATA;
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
ARR_DLL int ARR_DECL create_array(char *file_name, int **array, int numbers_amount)
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
ARR_DLL void ARR_DECL print_array_to_file(char *file_name, int *array_st, int *array_end)
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
ARR_DLL void ARR_DECL print_errors(int ch)
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

    if (ch == GOT_EMPTY_ARRAY)
        printf("GOT_EMPTY_ARRAY\n");
}
