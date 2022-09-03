#include "const.h"

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

// Чтение строки из файла
int read_string(FILE *f, char *string)
{
    char *ch;

    ch = fgets(string, TITLE_MAX + 2, f);

    if (ch == NULL)
        return INCORRECT_INPUT;

    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
    else if (strlen(string) > TITLE_MAX)
        return STR_OVERFLOW;
    if (string[0] == '\0' || string[0] == '\n' || string[0] == '\t')
        return EMPTY_STR;

    return OK;
}

// Чтение числа из файла
int read_number(FILE *f, int *number)
{
    int ch;
    char n;

    ch = fscanf(f, "%d", number);
    fscanf(f, "%c", &n);

    if (ch != 1)
        return INCORRECT_INPUT;

    if (*number <= 0)
        return INCORRECT_INPUT;

    return OK;
}

// Чтение структуры из файла
int read_struct(FILE *f, char *title, char *name, int *num)
{
    int ch = 0, number = 0;

    ch = read_string(f, title);

    if (ch == OK)
    {
        number += 1;
        ch = read_string(f, name);

        if (ch == OK)
        {
            number += 1;

            ch = read_number(f, num);

            if (ch == OK)
                number += 1;
        }
    }

    if (ch == STR_OVERFLOW)
        return STR_OVERFLOW;

    return number;
}

// Вывод фильмов
int print_films(struct film *films, int num)
{
    for (int i = 0; i < num; i++)
        printf("%s\n%s\n%d\n", films[i].title, films[i].name, films[i].year);

    return OK;
}

// Вывод одного фильма
void print_one_film(struct film film)
{
    printf("%s\n%s\n%d\n", film.title, film.name, film.year);
}
