#include <stdio.h>
#include <string.h>
#include "const.h"
#include "file_process.h"
#include "cdio.h"

// Проверка файла
int file_check(char **argv)
{
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return FILE_OPEN_ERR;

    if (ferror(f) != 0)
        return FILE_ERR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERR;

    return OK;
}

// Подсчет количества структур
int struct_count(char *file_name)
{
    FILE *f = fopen(file_name, "r");
    int count = 0;
    char title[MAX_BUF + 1], name[MAX_BUF + 1];
    int ch, num;

    ch = read_struct(f, title, name, &num);

    while (ch == 3)
    {
        count += 1;
        ch = read_struct(f, title, name, &num);
    }

    if (ch > 0)
    {
        fclose(f);
        return INCORRECT_INPUT;
    }

    fclose(f);

    return count;
}