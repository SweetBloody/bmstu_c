#ifndef LAB_10_01_01_LIST_H
#define LAB_10_01_01_LIST_H

#include "node.h"

// Поиск хвоста списка
node_t *get_tail(node_t **head);

// Поиск элемента в списке
node_t *find(node_t *head, const void *data, int (*comparator)(const void *a, const void *b));

// Элемент, находящийся в "хвосте" списка
void *pop_back(node_t **head);

// Добавление списка b в конец a
void append(node_t **head_a, node_t **head_b);

// Сортировка списка вставками
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

// Вставка элемента в отсортированный список
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

// Создание списка для тестов
void create_list(node_t **head, node_t **tail, int length);

// Сравнение двух списков
int list_cmp(node_t *head_a, node_t *head_b, int (*comparator)(const void *, const void *));

// Создание списка по данным значениям
void create_list_by_array(node_t **head, node_t **tail, int array[], int length);

// Компаратор целых чисел
int compare_int(const void *a, const void *b);

#endif //LAB_10_01_01_LIST_H
