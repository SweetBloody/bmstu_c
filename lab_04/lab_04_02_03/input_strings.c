#include <stdio.h>
#include <string.h>
#include "input_strings.h"
#include "const.h"

// Функция ввода двух строк
int input_strings(char *str1, char *str2)
{
    char *ch;

    printf("Enter first string:\n");
    ch = fgets(str1, MAX_LEN_STR + 2, stdin);

    if (ch == NULL)
        return INPUT_ERR;

    if ((char) str1[strlen(str1) - 1] != '\n')
        return STR_OVERFLOW;

    if (str1[0] == '\0' || str1[0] == '\n' || str1[0] == '\t')
        return EMPTY_STR;

    str1[strlen(str1) - 1] = '\0';

    printf("Enter second string:\n");
    ch = fgets(str2, MAX_LEN_STR + 2, stdin);

    if (ch == NULL)
        return INPUT_ERR;

    if ((char) str2[strlen(str2) - 1] != '\n')
        return STR_OVERFLOW;

    if (str2[0] == '\0' || str2[0] == '\n' || str2[0] == '\t')
        return EMPTY_STR;

    str2[strlen(str2) - 1] = '\0';

    return OK;
}
