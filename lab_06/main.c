#include "const.h"

int main(int argc, char **argv)
{
    int ch, films_number = 0;
    struct film films[MAX_LEN_STRUCT];

    if (argc != 3 && argc != 4)
        return INCORRECT_ARGS;

    if ((strcmp(argv[2], "title") != 0) &&
        (strcmp(argv[2], "name") != 0) &&
        (strcmp(argv[2], "year") != 0))
        return INCORRECT_ARGS;

    ch = file_check(argv);

    if (ch == FILE_OPEN_ERR)
        return FILE_OPEN_ERR;

    if (ch == FILE_ERR)
        return FILE_ERR;

    if (ch == FILE_CLOSE_ERR)
        return FILE_CLOSE_ERR;

    ch = add_to_array(argv, films, &films_number);

    if (ch == INCORRECT_INPUT)
        return INCORRECT_INPUT;

    if (ch == NUM_STRUCT_OVERFLOW)
        return NUM_STRUCT_OVERFLOW;

    if (ch == EMPTY_FILE)
        return EMPTY_FILE;

    if (ch == STR_OVERFLOW)
        return STR_OVERFLOW;

    if (argc == 3)
        print_films(films, films_number);

    if (argc == 4)
    {
        ch = find_by_key(argv, films, films_number);

        if (ch == INCORRECT_ARGS)
            return INCORRECT_ARGS;

        if (ch == NOT_FOUND)
        {
            printf("Not found\n");
            return OK;
        }
    }

    return OK;
}
