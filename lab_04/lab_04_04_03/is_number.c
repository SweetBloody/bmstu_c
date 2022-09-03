#include <stdio.h>
#include <ctype.h>
#include "is_number.h"
#include "const.h" // Константы

// Функция, определяющая, корректно ли введен номер в строке
int is_number(char *str)
{
    int index = 0, flag = 0;

    while (isspace(str[index]) != 0)
        index += 1;

    if ((str[index] != '+' && str[index] != '(') || (str[index] == '+' && str[index + 1] == '(') )
    {
        printf("NO");
        return OK;
    }

    if (str[index] == '+')
        flag = 1;

    index += 1;

    if (flag == 1)
    {
        while (isdigit(str[index]) != 0)
            index += 1;

        if (str[index] != '(')
        {
            printf("NO");
            return OK;
        }

        index += 1;
    }

    if (isdigit(str[index]) == 0 || isdigit(str[index + 1]) == 0 || isdigit(str[index + 2]) == 0)
    {
        printf("NO");
        return OK;
    }

    index += 3;

    if (str[index] != ')' || str[index + 1] != '-')
    {
        printf("NO");
        return OK;
    }

    index += 2;

    if (isdigit(str[index]) == 0 || isdigit(str[index + 1]) == 0 || isdigit(str[index + 2]) == 0)
    {
        printf("NO");
        return OK;
    }

    index += 3;

    for (int i = 0; i < 2; i++)
    {
        if (str[index] != '-')
        {
            printf("NO");
            return OK;
        }

        index += 1;

        if (isdigit(str[index]) == 0 || isdigit(str[index + 1]) == 0)
        {
            printf("NO");
            return OK;
        }

        index += 2;
    }

    while (isspace(str[index]) != 0)
        index += 1;

    if (str[index] != '\0')
    {
        printf("NO");
        return OK;
    }

    printf("YES");

    return OK;
}
