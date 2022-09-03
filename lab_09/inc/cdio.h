#ifndef CDIO_H
#define CDIO_H

#include <stdio.h>
#include "const.h"
#include "struct.h"

// Создание массива
struct film *create_array(int number);

// Освобождение памяти из под массива
void free_array(struct film *films, int amount);

// Чтение строки из файла
int read_string(FILE *f, char *string);

// Чтение числа из файла
int read_number(FILE *f, int *number);

// Чтение структуры из файла
int read_struct(FILE *f, char *title, char *name, int *num);

// Создание структуры фильма
int film_init(struct film *new_film, char *title, char *name, int year, int index, int len);

// Создание фильма (с выделением памяти)
struct film *film_create(char *title, char *name, int year);

// Освобождение памяти из под структуры фильма
void film_free(struct film *film);

// Вывод фильмов
int print_films(struct film *films, int num);

// Вывод одного фильма
void print_one_film(struct film film);

// Вывод сообщений об ошибках
void print_errors(int ch);

#endif // CDIO_H
