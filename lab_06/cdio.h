#ifndef CDIO_H
#define CDIO_H

#include "const.h"

// Проверка файла
int file_check(char **argv);

// Чтение строки из файла
int read_string(FILE *f, char *string);

// Чтение числа из файла
int read_number(FILE *f, int *number);

// Чтение структуры из файла
int read_struct(FILE *f, char *title, char *name, int *num);

// Вывод фильмов
int print_films(struct film *films, int num);

// Вывод одного фильма
void print_one_film(struct film film);

#endif // CDIO_H
