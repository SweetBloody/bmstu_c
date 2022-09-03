#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cdio.h"
#include "struct.h"
#include "const.h"

// Копирование одной структуры в другую
int film_copy(struct film *dst, struct film *src, int index, int len)
{
    return film_init(dst, src->title, src->name, src->year, index, len);
}

// Сортировка по полю title
void find_place_by_title(struct film *films, struct film *new_film, int num)
{
    int index, k = 0;

    while (k != num && strcmp(new_film->title, films[k].title) >= 0)
        k += 1;

    index = k;

    for (int i = num; i > index; i--)
        film_copy(&films[i], &films[i - 1], i, num);

    film_copy(&films[index], new_film, index, num);
}

// Сортировка по полю name
void find_place_by_name(struct film *films, struct film *new_film, int num)
{
    int index, k = 0;

    while (k != num && strcmp(new_film->name, films[k].name) >= 0)
        k += 1;

    index = k;

    for (int i = num; i > index; i--)
        film_copy(&films[i], &films[i - 1], i, num);

    film_copy(&films[index], new_film, index, num);
}

// Сортировка по полю year
void find_place_by_year(struct film *films, struct film *new_film, int num)
{
    int index, k = 0;

    while (k != num && new_film->year >= films[k].year)
        k += 1;

    index = k;

    for (int i = num; i > index; i--)
        film_copy(&films[i], &films[i - 1], i, num);

    film_copy(&films[index], new_film, index, num);
}


// Добавление структур в массив (сортировка сразу)
int add_to_array(char **argv, struct film *films, int *films_number)
{
    FILE *f = fopen(argv[1], "r");
    struct film *new_film;
    char title[MAX_BUF + 1], name[MAX_BUF + 1];
    int ch, index = 0, num;

    ch = read_struct(f, title, name, &num);

    if (ch == 0)
    {
        fclose(f);
        return EMPTY_FILE;
    }

    if (ch != 3)
    {
        fclose(f);
        return INCORRECT_INPUT;
    }

    while (ch == 3)
    {
        new_film = film_create(title, name, num);

        if (!new_film)
            return MEMORY_ERROR;

        if (strcmp(argv[2], "title") == 0)
            find_place_by_title(films, new_film, index);
        else if (strcmp(argv[2], "name") == 0)
            find_place_by_name(films, new_film, index);
        else
            find_place_by_year(films, new_film, index);

        film_free(new_film);
        index += 1;
        ch = read_struct(f, title, name, &num);
    }

    if (ch > 0)
    {
        fclose(f);
        return INCORRECT_INPUT;
    }

    *films_number = index;

    if (*films_number == 0)
    {
        fclose(f);
        return EMPTY_FILE;
    }

    fclose(f);

    return OK;
}

// Бинарный поиск по полю title
int bin_search_title(char *key, struct film *films, int films_number)
{
    int left = 0, right = films_number - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (strcmp(key, films[mid].title) < 0)
            right = mid - 1;
        else if (strcmp(key, films[mid].title) > 0)
            left = mid + 1;
        else
            return mid;
    }

    return -1;
}

// Бинарный поиск по полю name
int bin_search_name(char *key, struct film *films, int films_number)
{
    int left = 0, right = films_number - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (strcmp(key, films[mid].name) < 0)
            right = mid - 1;
        else if (strcmp(key, films[mid].name) > 0)
            left = mid + 1;
        else
            return mid;
    }

    return -1;
}

// Бинарный поиск по полю year
int bin_search_year(int key, struct film *films, int films_number)
{
    int left = 0, right = films_number - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (key < films[mid].year)
            right = mid - 1;
        else if (key > films[mid].year)
            left = mid + 1;
        else
            return mid;
    }

    return -1;
}

// Поиск фильма по значению поля
int find_by_key(char **argv, struct film *films, int films_number)
{
    int number = -1, index = 0;

    if (strcmp(argv[2], "title") == 0)
    {
        index = bin_search_title(argv[3], films, films_number);
        if (index == -1)
            return NOT_FOUND;
    }
    else if (strcmp(argv[2], "name") == 0)
    {
        index = bin_search_name(argv[3], films, films_number);
        if (index == -1)
            return NOT_FOUND;
    }
    else
    {
        number = atoi(argv[3]);

        if (number <= 0)
            return INCORRECT_ARGS;

        index = bin_search_year(number, films, films_number);

        if (index == -1)
            return NOT_FOUND;
    }

    print_one_film(films[index]);

    return OK;
}
