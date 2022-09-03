#include <stdio.h>
#include <string.h>
#include "input_string.h"
#include "const.h" // Константы

// Функция ввода строки
int input_string(char *str)
{
    char *ch;

    ch = fgets(str, MAX_LEN_STR + 2, stdin);

    if (ch == NULL)
        return INPUT_ERR;

    if (strlen(str) > MAX_LEN_STR)
        return STR_OVERFLOW;

    if (strlen(str) == 0)
        return EMPTY_STR;

    return OK;
}
