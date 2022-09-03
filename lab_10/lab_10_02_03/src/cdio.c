#include <stdio.h>
#include <string.h>
#include "cdio.h"
#include "const.h"

// Ввод строки
int input_string(char *string)
{
    char *ch;

    ch = fgets(string, MAX_LEN + 2, stdin);

    if (ch == NULL)
        return INCORRECT_INPUT;

    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';

    if (string[0] == '\0' || string[0] == '\n' || string[0] == '\t')
        return EMPTY_STR;

    return OK;
}

// Ввод числа
int input_number(int *number)
{
    int ch;

    ch = scanf("%d", number);

    if (ch != 1)
        return INCORRECT_INPUT;

    if (*number <= 0)
        return INCORRECT_VALUE;

    return OK;
}

// Вывод числа в виде степеней простых множителей
void print_simple_list(node_t *head)
{
    node_t *cur = head;

    while (cur->next != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d L\n", cur->data);
}