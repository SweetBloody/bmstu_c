#include "../inc/const.h"

// Функция фильтр
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int *start_src = (int *) pb_src, *start_dst, count = 0;

    // Находим количество подходящих элементов
    while (start_src < pe_src)
    {
        if (*start_src < 0)
            break;

        count += 1;
        start_src += 1;
    }

    if (count == 0)
        return GOT_EMPTY_ARRAY;

    // Выделяем память под подходящие элементы
    *pb_dst = malloc(count * sizeof(int));

    if (*pb_dst == NULL)
        return MEMORY_GET_ERROR;

    // Копируем подходящие элементы из старого массива в новый
    start_src = (int *) pb_src;
    start_dst = *pb_dst;
    *pe_dst = *pb_dst + count;

    while (start_dst < *pe_dst)
    {
        *start_dst = *start_src;
        start_src += 1;
        start_dst += 1;
    }

    return OK;
}

// Компаратор целых чисел
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

// Компаратор чаров
int compare_char(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

// Компаратор вещественных чисел
int compare_double(const void *a, const void *b)
{
    double delta = *(double*)a - *(double*)b;

    if (delta > EPS && delta > 0)
        return 1;
    else if (-delta < -EPS && delta < 0)
        return -1;
    else
        return 0;
}

// Замена местами двух элементов
void swap_elems(char *elem1, char *elem2, size_t size)
{
    char tmp;

    for (int i = 0; i < (int) size; i++)
    {
        tmp = *elem1;
        *elem1 = *elem2;
        *elem2 = tmp;

        elem1 += 1;
        elem2 += 1;
    }
}

// Сортировка выбором
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    char *end = (char *) first + (number - 1) * size;
    char *max, *pa_j, *pa_i;

    for (int i = number; i > 0; i--)
    {
        pa_i = end - (number - i) * size;
        max = pa_i;
        pa_j = end - size * (number - i + 1);
        for (int j = i - 1; j > 0; j--)
        {
            if (comparator((void *) pa_j, (void *) max) > 0)
                max = pa_j;

            pa_j -= size;
        }

        swap_elems(max, pa_i, size);
    }
}
