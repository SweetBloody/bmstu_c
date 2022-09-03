#ifndef LAB_12_02_01_PROCESS_H
#define LAB_12_02_01_PROCESS_H

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#include <stdlib.h>

#define ARR_DECL __cdecl

// Функция фильтр
ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, int mode);

// Компаратор целых чисел
ARR_DLL int ARR_DECL compare_int(const void *a, const void *b);

// Компаратор чаров
ARR_DLL int ARR_DECL compare_char(const void *a, const void *b);

// Компаратор вещественных чисел
ARR_DLL int ARR_DECL compare_double(const void *a, const void *b);

// Сортировка выбором
ARR_DLL void ARR_DECL mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));

#endif //LAB_12_02_01_PROCESS_H
