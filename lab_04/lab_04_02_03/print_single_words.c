#include <stdio.h>
#include <string.h>
#include "print_single_words.h"
#include "const.h"

// Функция, которая выводит неповторяющиеся в массивах слова
int print_single_words(char words1[][MAX_LEN_WORD + 1], int len1, char words2[][MAX_LEN_WORD + 1], int len2)
{
    int flag, flag_result = 0;

    for (int i = 0; i < len1; i++)
    {
        flag = 0;

        for (int k = 0; k < len1; k++)
            if (k != i && strcmp(words1[i], words1[k]) == 0)
            {
                flag = 1;
                break;
            }

        if (flag == 0)
            for (int m = 0; m < len2; m++)
                if (strcmp(words1[i], words2[m]) == 0)
                {
                    flag = 1;
                    break;
                }

        if (flag == 0)
        {
            if (flag_result == 0)
            {
                printf("Result:");
                flag_result = 1;
            }

            printf(" %s", words1[i]);
        }
    }

    for (int i = 0; i < len2; i++)
    {
        flag = 0;

        for (int k = 0; k < len2; k++)
            if (k != i && strcmp(words2[i], words2[k]) == 0)
            {
                flag = 1;
                break;
            }

        if (flag == 0)
            for (int m = 0; m < len1; m++)
                if (strcmp(words2[i], words1[m]) == 0)
                {
                    flag = 1;
                    break;
                }

        if (flag == 0)
        {
            if (flag_result == 0)
            {
                printf("Result:");
                flag_result = 1;
            }

            printf(" %s", words2[i]);
        }
    }

    if (flag_result == 0)
        return NO_WORDS;
    else
        return OK;
}

