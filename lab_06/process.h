#ifndef PROCESS_H
#define PROCESS_H

#include "const.h"

// Сортировка по полю title
void find_place_by_title(struct film *films, struct film new_film, int num);

// Сортировка по полю name
void find_place_by_name(struct film *films, struct film new_film, int num);

// Сортировка по полю year
void find_place_by_year(struct film *films, struct film new_film, int num);

// Добавление структур в массив (сортировка сразу)
int add_to_array(char **argv, struct film *films, int *films_number);

// Бинарный поиск по полю title
int bin_search_title(char *key, struct film *films, int films_number);

// Бинарный поиск по полю name
int bin_search_name(char *key, struct film *films, int films_number);

// Бинарный поиск по полю year
int bin_search_year(int key, struct film *films, int films_number);

// Поиск фильма по значению поля
int find_by_key(char **argv, struct film *films, int films_number);

#endif // PROCESS_H
