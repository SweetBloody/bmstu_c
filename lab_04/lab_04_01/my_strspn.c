#include "my_strspn.h"

int my_strspn(const char *str1, const char *str2)
{
    int flag, i;

    for (i = 0; str1[i] != '\0'; i++)
    {
        flag = 0;

        for (int j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
                flag = 1;
        }

        if (flag == 0)
            return i;
    }

    return i;
}
