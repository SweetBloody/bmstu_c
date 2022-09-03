#include <stdlib.h>
#include <math.h>
#include "process.h"
#include "const.h"

// Создание массива простых чисел
static int *eratosthen_numbers(int max, int *length)
{
    int *array, *simple_num_array;
    int count = 2, num = 2, index = 2;

    *length = 0;

    array = calloc(max + 1, sizeof(int));

    if (array == NULL)
        return NULL;

    for (int i = 0; i <= max; i++)
        array[i] = i;

    array[1] = 0;

    while (num <= max)
    {
        if (array[index] != 0)
        {
            for (int j = 2 * num; j <= max; j += num)
            {
                if (array[j] != 0)
                    count += 1;
                array[j] = 0;
            }
        }

        index += 1;
        num += 1;
    }

    simple_num_array = calloc(max + 1 - count, sizeof(int));

    if (simple_num_array == NULL)
    {
        free(array);
        return NULL;
    }

    for (int i = 0; i <= max; i++)
    {
        if (array[i] != 0)
        {
            simple_num_array[*length] = array[i];
            *length += 1;
        }
    }

    free(array);

    return simple_num_array;
}

// Перевод числа в вид списка степеней простых множителей
node_t *num_to_simple_list(int number)
{
    node_t *head = NULL, *cur = NULL;
    int *array, length = 0, index = 0;

    array = eratosthen_numbers(number, &length);

    if (array == NULL)
        return NULL;

    while (number != 1)
    {
        cur = list_add(&cur, 0);

        if (cur == NULL)
            return NULL;

        if (head == NULL)
            head = cur;

        while (number % array[index] == 0)
        {
            cur->data += 1;
            number /= array[index];
        }

        index += 1;
    }

    free(array);

    return head;
}

// Перевод списка степеней простых множителей в число
static int simple_list_to_num(node_t **head, int max)
{
    node_t *cur = *head;
    int number = 1, length, index = 0;
    int *array = eratosthen_numbers(max, &length);

    if (array == NULL)
        return MEMORY_GET_ERROR;

    while (cur != NULL)
    {
        number *= (int) pow(array[index], cur->data);
        index += 1;
        cur = cur->next;
    }

    free(array);

    return number;
}

// Нахождение длины списка
static int list_len(node_t *head)
{
    node_t *cur = head;
    int length = 0;

    while (cur != NULL)
    {
        length += 1;
        cur = cur->next;
    }

    return length;
}

// Перемножение двух чисел
void muliply(node_t **head_1, node_t **head_2)
{
    node_t *tmp = NULL;
    node_t *cur_1 = NULL;
    node_t *cur_2 = NULL;
    int len_1 = list_len(*head_1);
    int len_2 = list_len(*head_2);

    if (len_2 > len_1)
    {
        tmp = *head_1;
        *head_1 = *head_2;
        *head_2 = tmp;
    }

    cur_1 = *head_1;
    cur_2 = *head_2;

    while (cur_2 != NULL)
    {
        cur_1->data += cur_2->data;
        cur_1 = cur_1->next;
        cur_2 = cur_2->next;
    }
}

// Возведение числа в степень
void sqr(node_t **head)
{
    node_t *cur = *head;

    while (cur != NULL)
    {
        cur->data *= 2;
        cur = cur->next;
    }
}

// Минимальное из двух чисел
static int minimum(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

// Деление двух чисел без остатка
node_t *division(node_t **head_1, node_t **head_2, int max)
{
    node_t *head_res = NULL;
    node_t *tmp = NULL, *cur_1 = NULL, *cur_2 = NULL;
    int len_1 = list_len(*head_1);
    int len_2 = list_len(*head_2);
    int min, number_1, number_2, result;

    if (len_2 > len_1)
    {
        tmp = *head_1;
        *head_1 = *head_2;
        *head_2 = tmp;
    }

    cur_1 = *head_1;
    cur_2 = *head_2;

    while (cur_2 != NULL)
    {
        min = minimum(cur_1->data, cur_2->data);
        cur_1->data -= min;
        cur_2->data -= min;

        cur_1 = cur_1->next;
        cur_2 = cur_2->next;
    }

    number_1 = simple_list_to_num(head_1, max);
    number_2 = simple_list_to_num(head_2, max);

    if (number_1 == MEMORY_GET_ERROR || number_2 == MEMORY_GET_ERROR)
        return NULL;

    if (len_2 > len_1)
        result = number_2 / number_1;
    else
        result = number_1 / number_2;

    head_res = num_to_simple_list(result);

    if (head_res == NULL)
        return NULL;

    return head_res;
}