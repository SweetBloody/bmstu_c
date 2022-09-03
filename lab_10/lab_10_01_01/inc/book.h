#ifndef LAB_10_01_01_BOOK_H
#define LAB_10_01_01_BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

#define MAX_LEN 50 // Максимальная длина названия

typedef struct
{
    char title[MAX_LEN + 1];
    int year;
} book_t;

// Ввод данных (структур) списка из файла
int input_list_from_file_book(char *file_name, node_t **head, node_t **tail);

// Создание структуры книги по входным значениям полей
book_t *create_book(char *title, char *number);

// Компаратор книг по году
int compare_book_year(const void *a, const void *b);

// Компаратор книг
int compare_book(const void *a, const void *b);

#endif //LAB_10_01_01_BOOK_H
