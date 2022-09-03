#ifndef LAB_10_01_01_NODE_H
#define LAB_10_01_01_NODE_H

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

// Создание узла списка
node_t *list_node(void *data);

// Добавление узла в список
node_t *list_add(node_t **prev, void *data);

// Поиск предыдущего элемента
node_t *find_prev(node_t **head, node_t **node);

// Удаление узла из списка
void *list_delete(node_t **head, node_t **tail);

#endif //LAB_10_01_01_NODE_H
