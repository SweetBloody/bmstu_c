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

    if ((char) str[strlen(str) - 1] != '\n')
        return STR_OVERFLOW;

    if (str[0] == '\0' || str[0] == '\n' || str[0] == '\t')
        return EMPTY_STR;

    str[strlen(str) - 1] = '\0';

    return OK;
}
