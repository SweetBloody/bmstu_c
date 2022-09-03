#ifndef LAB_10_02_03_PROCESS_H
#define LAB_10_02_03_PROCESS_H

#include "node.h"

// Перевод числа в вид списка степеней простых множителей
node_t *num_to_simple_list(int number);

// Перемножение двух чисел
void muliply(node_t **head_1, node_t **head_2);

// Возведение числа в степень
void sqr(node_t **head);

// Деление двух чисел без остатка
node_t *division(node_t **head_1, node_t **head_2, int max);

#endif //LAB_10_02_03_PROCESS_H
