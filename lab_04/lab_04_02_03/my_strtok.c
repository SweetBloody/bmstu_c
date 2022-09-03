#include "my_strtok.h"
#include "const.h"

// Функция, разделяющая строку на слова
int my_strtok(char *str, char words[][MAX_LEN_WORD + 1], int *number)
{
    int i = 0, index_word = 0, index_letter = 0, flag = 1;

    while (str[i] != '\0')
    {
        if ((char) str[i] != ' ' && (char) str[i] != ',' && (char) str[i] != ';' && (char) str[i] != ':' && (char) str[i] != '-' && (char) str[i] != '.' && (char) str[i] != '!' && (char) str[i] != '?')
        {
            flag = 0;

            if (index_letter == MAX_LEN_WORD)
                return WORD_OVERFLOW;

            words[index_word][index_letter] = str[i];
            index_letter += 1;
        }
        else
        {
            if (flag == 0)
            {
                words[index_word][index_letter] = '\0';
                index_word += 1;
                index_letter = 0;
                *number += 1;
            }

            flag = 1;
        }

        i += 1;
    }

    if (flag == 0)
    {
        words[index_word][index_letter] = '\0';
        *number += 1;
    }

    return OK;
}
