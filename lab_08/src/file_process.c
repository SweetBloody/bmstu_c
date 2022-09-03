#include <stdio.h>
#include <string.h>
#include "const.h"
#include "file_process.h"

// Проверка аргументов командной строки
int args_check(int argc, char **argv)
{
    if (argc != 4 && argc != 5)
        return INCORRECT_ARGS;

    if (strcmp(argv[1], "a") != 0 && strcmp(argv[1], "m") != 0 && strcmp(argv[1], "o") != 0)
        return INCORRECT_ARGS;

    if ((argc == 4 && strcmp(argv[1], "o") != 0) || (argc == 5 && strcmp(argv[1], "o") == 0))
        return INCORRECT_ARGS;

    return OK;
}

// Проверка файла
int file_check(char *file_name, char *mode)
{
    FILE *f = fopen(file_name, mode);

    if (f == NULL)
        return FILE_OPEN_ERR;

    if (ferror(f) != 0)
        return FILE_ERR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERR;

    return OK;
}
