#include <stdio.h>
#include "my_strpbrk.h"

char *my_strpbrk(char *str1, char *str2)
{
    char *s2;

    while (*str1 != '\0')
    {
        s2 = str2;

        while (*s2 != '\0')
        {
            if (*str1 == *s2)
                return (char *) str1;
            s2 += 1;
        }

        str1 += 1;
    }

    return NULL;
}
