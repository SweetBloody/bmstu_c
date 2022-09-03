#ifndef LAB_07_PROCESS_H
#define LAB_07_PROCESS_H

// Функция фильтр
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

// Компаратор целых чисел
int compare_int(const void *a, const void *b);

// Компаратор чаров
int compare_char(const void *a, const void *b);

// Компаратор вещественных чисел
int compare_double(const void *a, const void *b);

// Сортировка выбором
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));

#endif //LAB_07_PROCESS_H
