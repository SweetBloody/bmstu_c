#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "struct.h"

// Создание массива
struct film *create_array(int number)
{
    struct film *films;

    films = malloc(number * sizeof(struct film));

    if (films == NULL)
        return NULL;

    return films;
}

// Освобождение памяти из под массива
void free_array(struct film *films, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        free(films[i].title);
        free(films[i].name);
    }

    free(films);
}

// Чтение строки из файла
int read_string(FILE *f, char *string)
{
    char *ch;

    ch = fgets(string, 100, f);

    if (ch == NULL)
        return INCORRECT_INPUT;

    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';

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

    return number;
}

// Создание структуры фильма
int film_init(struct film *new_film, char *title, char *name, int year, int index, int len)
{
    char *ptitle = strdup(title);
    char *pname = strdup(name);

    if (!ptitle || !pname)
        return MEMORY_ERROR;

    if (len != 0 && index != len)
    {
        free(new_film->title);
        free(new_film->name);
    }

    new_film->title = ptitle;
    new_film->name = pname;
    new_film->year = year;

    return OK;
}

// Создание фильма (с выделением памяти)
struct film *film_create(char *title, char *name, int year)
{
    struct film *film = malloc(sizeof(struct film));

    if (!film)
        return NULL;

    film->title = strdup(title);
    film->name = strdup(name);

    if (!film->title || !film->name)
    {
        free(film);
        return NULL;
    }

    film->year = year;

    return film;
}

// Освобождение памяти из под структуры фильма
void film_free(struct film *film)
{
    free(film->title);
    free(film->name);
    free(film);
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

// Вывод сообщений об ошибках
void print_errors(int ch)
{
    if (ch == INCORRECT_ARGS)
        printf("INCORRECT_ARGS\n");

    if (ch == FILE_OPEN_ERR)
        printf("FILE_OPEN_ERR\n");

    if (ch == FILE_CLOSE_ERR)
        printf("FILE_CLOSE_ERR\n");

    if (ch == FILE_ERR)
        printf("FILE_ERR\n");

    if (ch == EMPTY_FILE)
        printf("EMPTY_FILE\n");

    if (ch == INCORRECT_INPUT)
        printf("INCORRECT_INPUT\n");

    if (ch == EMPTY_STR)
        printf("EMPTY_STR\n");
}
