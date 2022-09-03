#include <stdlib.h>
#include "const.h"

// Функция заполнения массива числами Фибоначчи
int fib_array(int *array, int size)
{
    if (array == NULL)
        return NULL_ARRAY;

    if (size <= 0)
        return INCORRECT_SIZE;

    if (size >= 1)
        array[0] = 0;

    if (size >= 2)
        array[1] = 1;

    for (int i = 2; i < size; i++)
        array[i] = array[i - 1] + array[i - 2];

    return OK;
}

// Функция определяющая, есть ли данный элемент в массиве
static int is_in_array(const int *array, int size, int number)
{
    for (int i = 0; i < size; i++)
        if (array[i] == number)
            return 1;

    return 0;
}

// Функция, которая из одного массива помещает во второй массив
// первое вхождение каждого элемента первого массива
int single_elems_array(int *src_arr, int src_arr_size, int *dst_arr, int *dst_arr_size)
{
    int count = 0;
    int *temp = malloc(src_arr_size * sizeof(int));
    if (!temp)
        return MEMORY_GET_ERR;

    if (src_arr == NULL)
        return NULL_ARRAY;

    if (src_arr_size <= 0)
        return INCORRECT_SIZE;

    for (int i = 0; i < src_arr_size; i++)
        if (is_in_array(temp, count, src_arr[i]) == 0)
        {
            temp[count] = src_arr[i];
            count++;
        }

    if (count > *dst_arr_size)
    {
        free(temp);
        *dst_arr_size = count;
        return NEED_MORE_MEM;
    }
    else
    {
        if (dst_arr == NULL)
        {
            free(temp);
            return NULL_ARRAY;
        }

        for (int i = 0; i < count; i++)
            dst_arr[i] = temp[i];
    }

    *dst_arr_size = count;
    free(temp);

    return OK;
}