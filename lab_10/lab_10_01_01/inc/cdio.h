#ifndef LAB_10_01_01_CDIO_H
#define LAB_10_01_01_CDIO_H

#include <stdio.h>
#include "node.h"

// Проверка файла
int file_check(char *file_name);

// Чтение строки из файла
int read_string(FILE *f, char *string);

// Чтение числа из файла
int read_number(FILE *f, int *number);

// Ввод данных (целых чисел) списка из файла
int input_list_from_file_int(char *file_name, node_t **head, node_t **tail);

// Удаление списка
void free_list(node_t **head, node_t **tail);

// Вывод последовательности чисел
void print_list_int(node_t *head);

// Вывод последовательности чисел
void print_list_book(node_t *head);

#endif //LAB_10_01_01_CDIO_H
