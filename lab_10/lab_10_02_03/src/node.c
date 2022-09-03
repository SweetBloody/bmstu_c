#include <stdlib.h>
#include "node.h"

// Создание узла списка
static node_t *list_node(int data)
{
    node_t *node = NULL;

    node = calloc(1, sizeof(node_t));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

// Добавление узла в список
node_t *list_add(node_t **prev, int data)
{
    node_t *node = NULL;

    node = list_node(data);

    if (node == NULL)
        return NULL;

    if (*prev)
        (*prev)->next = node;

    return node;
}

// Освобождение памяти из под списка (удаление)
void list_free(node_t **head)
{
    node_t *next;

    while (*head != NULL)
    {
        next = (*head)->next;
        free(*head);
        *head = next;
    }

    *head = NULL;
}

// Создание списка по данным значениям
node_t *create_list_by_array(int array[], int length)
{
    node_t *head = NULL, *cur = NULL;

    for (int i = 0; i < length; i++)
    {
        cur = list_add(&cur, array[i]);

        if (head == NULL)
            head = cur;
    }

    return head;
}

// Сравнение двух списков
int list_cmp(node_t *head_a, node_t *head_b)
{
    int flag = 0;

    while (head_a != NULL && flag == 0)
    {
        if (head_a->data != head_b->data)
            flag = 1;

        head_a = head_a->next;
        head_b = head_b->next;
    }

    return flag;
}