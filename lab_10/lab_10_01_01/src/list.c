#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Поиск хвоста списка
node_t *get_tail(node_t **head)
{
    node_t *tail = *head;

    if (!tail)
        return tail;

    while (tail->next != NULL)
        tail = tail->next;

    return tail;
}

// Поиск элемента в списке
node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *cur = head;

    if (head == NULL)
        return NULL;

    while (cur != NULL && comparator(cur->data, data) != 0)
        cur = cur->next;

    return cur;
}

// Элемент, находящийся в "хвосте" списка
void *pop_back(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;

    node_t *cur = *head;
    void *data;


    cur = get_tail(head);
    data = list_delete(head, &cur);

    return data;
}

// Добавление списка b в конец a
void append(node_t **head_a, node_t **head_b)
{
    node_t *cur_a = *head_a;
    node_t *cur_b = *head_b;

    if (!(*head_b))
        return;

    if (*head_a)
        cur_a = get_tail(head_a);

    while (cur_b->next != NULL)
    {
        cur_a = list_add(&cur_a, cur_b->data);

        if (!(*head_a))
            *head_a = cur_a;

        cur_b = cur_b->next;
    }
    cur_a = list_add(&cur_a, cur_b->data);

    while (cur_b != NULL)
        list_delete(head_b, &cur_b);
}

// Вставка элемента в отсортированный список
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    node_t *cur = *head;

    while (cur != NULL && comparator(cur->data, element->data) < 1)
        cur = cur->next;

    element->next = cur;

    if (*head == cur)
        *head = element;
    else
    {
        cur = find_prev(head, &cur);
        cur->next = element;
    }
}

// Сортировка списка вставками
node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *new_head = NULL, *tmp = NULL;

    while (head != NULL)
    {
        tmp = list_node(head->data);
        sorted_insert(&new_head, tmp, comparator);
        tmp = head->next;
        free(head);
        head = tmp;
    }

    return new_head;
}

// Создание списка для тестов
void create_list(node_t **head, node_t **tail, int length)
{
    int *tmp;

    for (int i = 0; i < length; i++)
    {
        tmp = calloc(1, sizeof(int));
        *tmp = i;
        *tail = list_add(tail, tmp);

        if (!(*head))
            *head = *tail;
    }
}

// Сравнение двух списков
int list_cmp(node_t *head_a, node_t *head_b, int (*comparator)(const void *, const void *))
{
    int flag = 0;

    while (head_a != NULL && flag == 0)
    {
        if (comparator(head_a->data, head_b->data) != 0)
            flag = 1;

        head_a = head_a->next;
        head_b = head_b->next;
    }

    return flag;
}

// Создание списка по данным значениям
void create_list_by_array(node_t **head, node_t **tail, int array[], int length)
{
    int *tmp;

    for (int i = 0; i < length; i++)
    {
        tmp = calloc(1, sizeof(int));
        *tmp = array[i];
        *tail = list_add(tail, tmp);

        if (!(*head))
            *head = *tail;
    }
}

// Компаратор целых чисел
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
