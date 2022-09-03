#include <stdlib.h>
#include <string.h>
#include "cdio.h"
#include "process.h"
#include "file_process.h"
#include "const.h"

int main(int argc, char **argv)
{
    int ch, number_amount = 0, *array, *new_array_st, *new_array_end;

    ch = args_check(argc, argv);

    if (ch != OK)
    {
        print_errors(ch);
        return ch;
    }

    ch = file_check(argv[1]);

    if (ch != OK)
    {
        print_errors(ch);
        return ch;
    }

    ch = count_numbers_amount(argv[1], &number_amount);

    if (ch != OK)
    {
        print_errors(ch);
        return ch;
    }

    array = malloc(number_amount * sizeof(int));

    if (array == NULL)
        return MEMORY_GET_ERROR;

    ch = create_array(argv[1], &array, number_amount);

    if (ch != OK)
    {
        print_errors(ch);
        return ch;
    }


    if (argc == 4 && strcmp(argv[3], "f") == 0)
    {
        ch = key(array, array + number_amount, &new_array_st, &new_array_end, 1);
        if (ch == MEMORY_GET_ERROR)
        {
            print_errors(ch);
            return ch;
        }

        new_array_st = malloc(ch * sizeof(int));

        if (new_array_st == NULL)
            return MEMORY_GET_ERROR;

        ch = key(array, array + number_amount, &new_array_st, &new_array_end, 2);

        if (ch != OK)
        {
            print_errors(ch);
            free(array);
            return ch;
        }

        free(array);
        mysort(new_array_st, new_array_end - new_array_st, sizeof(int), compare_int);
        print_array_to_file(argv[2], new_array_st, new_array_end);
        free(new_array_st);
    }
    else
    {
        mysort(array, number_amount, sizeof(int), compare_int);
        print_array_to_file(argv[2], array, array + number_amount);
        free(array);
    }

    return ch;
}
