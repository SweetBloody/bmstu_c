#include <stdlib.h>
#include "node.h"

// Создание узла списка
node_t *list_node(void *data)
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
node_t *list_add(node_t **prev, void *data)
{
    node_t *node = NULL;

    node = list_node(data);

    if (node == NULL)
        return NULL;

    if (*prev)
        (*prev)->next = node;

    return node;
}

// Поиск предыдущего элемента
node_t *find_prev(node_t **head, node_t **node)
{
    node_t *cur = *head;

    if (*node == *head)
        return NULL;

    while (cur->next != *node)
        cur = cur->next;

    return cur;
}

// Удаление узла из списка
void *list_delete(node_t **head, node_t **tail)
{
    node_t *prev = NULL;
    void *data = NULL;

    if (*tail)
    {
        prev = find_prev(head, tail);
        data = (*tail)->data;
        free(*tail);
        *tail = prev;
        if (*tail)
            (*tail)->next = NULL;
        else
            *head = NULL;
    }

    return data;
}