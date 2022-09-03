#ifndef LAB_10_02_03_NODE_H
#define LAB_10_02_03_NODE_H

typedef struct node node_t;

struct node
{
    int data;
    node_t *next;
};

// Добавление узла в список
node_t *list_add(node_t **prev, int data);

// Освобождение памяти из под списка (удаление)
void list_free(node_t **head);

// Создание списка по данным значениям
node_t *create_list_by_array(int array[], int length);

// Сравнение двух списков
int list_cmp(node_t *head_a, node_t *head_b);

#endif //LAB_10_02_03_NODE_H
