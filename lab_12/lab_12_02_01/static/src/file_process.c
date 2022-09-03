#include <stdio.h>
#include <string.h>
#include "file_process.h"
#include "const.h"

// Проверка аргументов командной строки
int args_check(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
        return INCORRECT_ARGS;

    if (argc == 4 && strcmp(argv[3], "f") != 0)
        return INCORRECT_ARGS;

    return OK;
}

// Проверка файла
int file_check(char *file_name)
{
    FILE *f = fopen(file_name, "r");

    if (f == NULL)
        return FILE_OPEN_ERR;

    if (ferror(f) != 0)
        return FILE_ERR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERR;

    return OK;
}
