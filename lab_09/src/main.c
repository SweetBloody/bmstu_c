#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "file_process.h"
#include "process.h"
#include "cdio.h"
#include "struct.h"

int main(int argc, char **argv)
{
    int ch, films_number = 0, amount;
    struct film *films;

    if (argc != 3 && argc != 4)
        return INCORRECT_ARGS;

    if ((strcmp(argv[2], "title") != 0) &&
        (strcmp(argv[2], "name") != 0) &&
        (strcmp(argv[2], "year") != 0))
        return INCORRECT_ARGS;

    ch = file_check(argv);

    if (ch != OK)
        return ch;

    amount = struct_count(argv[1]);

    if (amount == 0)
        return EMPTY_FILE;

    if (amount == INCORRECT_INPUT)
        return INCORRECT_INPUT;

    films = create_array(amount);

    if (films == NULL)
        return MEMORY_ERROR;

    ch = add_to_array(argv, films, &films_number);

    if (ch != OK)
    {
        free_array(films, amount);
        return ch;
    }

    if (argc == 3)
        print_films(films, films_number);

    if (argc == 4)
    {
        ch = find_by_key(argv, films, films_number);

        if (ch == INCORRECT_ARGS)
        {
            free_array(films, amount);
            return INCORRECT_ARGS;
        }

        if (ch == NOT_FOUND)
        {
            printf("Not found\n");
            free_array(films, amount);
            return OK;
        }
    }

    free_array(films, amount);

    return OK;
}
