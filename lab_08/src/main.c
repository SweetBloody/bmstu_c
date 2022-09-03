#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "file_process.h"
#include "cdio.h"
#include "process.h"

int main(int argc, char **argv)
{
    int ch, row_1, column_1, row_2, column_2, *result_array;
    double **matrix_1, **matrix_2, **matrix_res, *start_string_1, *start_string_2, *start_string_res;

    ch = args_check(argc, argv);

    if (ch != OK)
    {
        print_errors(ch);
        return ch;
    }

    ch = file_check(argv[2], "r");

    if (ch != OK)
    {
        print_errors(ch);
        return ch;
    }

    ch = input_matrix_size(argv[2], &row_1, &column_1);

    if (ch != OK)
    {
        print_errors(ch);
        return ch;
    }

    matrix_1 = create_matrix(row_1, column_1);

    if (matrix_1 == NULL)
    {
        print_errors(MEMORY_GET_ERROR);
        return MEMORY_GET_ERROR;
    }

    start_string_1 = matrix_1[0];

    ch = input_matrix(argv[2], matrix_1, row_1, column_1);

    if (ch != OK)
    {
        free_matrix(matrix_1, start_string_1);
        print_errors(ch);
        return ch;
    }

    // Если сложение или умножение
    if (strcmp(argv[1], "a") == 0 || strcmp(argv[1], "m") == 0)
    {
        ch = file_check(argv[3], "r");

        if (ch != OK)
        {
            free_matrix(matrix_1, start_string_1);
            print_errors(ch);
            return ch;
        }

        ch = file_check(argv[4], "w");

        if (ch != OK)
        {
            free_matrix(matrix_1, start_string_1);
            print_errors(ch);
            return ch;
        }

        ch = input_matrix_size(argv[3], &row_2, &column_2);

        if (ch != OK)
        {
            free_matrix(matrix_1, start_string_1);
            print_errors(ch);
            return ch;
        }

        matrix_2 = create_matrix(row_2, column_2);

        if (matrix_2 == NULL)
        {
            free_matrix(matrix_1, start_string_1);
            print_errors(MEMORY_GET_ERROR);
            return MEMORY_GET_ERROR;
        }

        start_string_2 = matrix_2[0];

        ch = input_matrix(argv[3], matrix_2, row_2, column_2);

        if (ch != OK)
        {
            free_matrix(matrix_1, start_string_1);
            free_matrix(matrix_2, start_string_2);
            print_errors(ch);
            return ch;
        }

        // Если сложение
        if (strcmp(argv[1], "a") == 0)
        {
            ch = addition_check(row_1, column_1, row_2, column_2);

            if (ch != OK)
            {
                free_matrix(matrix_1, start_string_1);
                free_matrix(matrix_2, start_string_2);
                print_errors(ch);
                return ch;
            }

            matrix_res = create_matrix(row_1, column_1);

            if (matrix_res == NULL)
            {
                free_matrix(matrix_1, start_string_1);
                free_matrix(matrix_2, start_string_2);
                print_errors(MEMORY_GET_ERROR);
                return MEMORY_GET_ERROR;
            }

            start_string_res = matrix_res[0];

            matrix_addition(matrix_1, matrix_2, matrix_res, row_1, column_1);
            print_matrix_to_file(argv[4], matrix_res, row_1, column_1);
        }
        // Если умножение
        else
        {
            ch = multiply_check(column_1, row_2);

            if (ch != OK)
            {
                free_matrix(matrix_1, start_string_1);
                free_matrix(matrix_2, start_string_2);
                print_errors(ch);
                return ch;
            }

            matrix_res = create_matrix(row_1, column_2);

            if (matrix_res == NULL)
            {
                free_matrix(matrix_1, start_string_1);
                free_matrix(matrix_2, start_string_2);
                print_errors(MEMORY_GET_ERROR);
                return MEMORY_GET_ERROR;
            }

            start_string_res = matrix_res[0];

            matrix_multiply(matrix_1, row_1, column_1, matrix_2, column_2, matrix_res);
            print_matrix_to_file(argv[4], matrix_res, row_1, column_2);
        }

        free_matrix(matrix_1, start_string_1);
        free_matrix(matrix_2, start_string_2);
        free_matrix(matrix_res, start_string_res);
    }
    else
    {
        ch = file_check(argv[3], "w");

        if (ch != OK)
        {
            free_matrix(matrix_1, start_string_1);
            print_errors(ch);
            return ch;
        }

        if (row_1 + 1 != column_1)
        {
            free_matrix(matrix_1, start_string_1);
            print_errors(GAUSS_ERROR);
            return GAUSS_ERROR;
        }

        result_array = create_array(row_1);

        if (result_array == NULL)
        {
            free_matrix(matrix_1, start_string_1);
            print_errors(MEMORY_GET_ERROR);
            return MEMORY_GET_ERROR;
        }

        ch = matrix_null_col_check(matrix_1, row_1, column_1);

        if (ch != OK)
        {
            free_matrix(matrix_1, start_string_1);
            free(result_array);
            print_errors(ch);
            return ch;
        }

        ch = gauss(matrix_1, row_1, column_1, result_array);

        if (ch != OK)
        {
            free_matrix(matrix_1, start_string_1);
            free(result_array);
            print_errors(ch);
            return ch;
        }

        print_array_to_file(argv[3], matrix_1, column_1, result_array, row_1);

        free_matrix(matrix_1, start_string_1);
        free(result_array);
    }

    return OK;
}
