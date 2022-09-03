#ifndef LAB_12_02_01_PROCESS_H
#define LAB_12_02_01_PROCESS_H

#include <stdlib.h>

// Функция фильтр
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, int mode);

// Компаратор целых чисел
int compare_int(const void *a, const void *b);

// Компаратор чаров
int compare_char(const void *a, const void *b);

// Компаратор вещественных чисел
int compare_double(const void *a, const void *b);

// Сортировка выбором
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));

#endif //LAB_12_02_01_PROCESS_H
