#include <string.h>
#include "words_array.h"
#include "const.h" // Константы

// Функция создания массива слов строки
int words_array(char *str, char words[][MAX_LEN_WORD + 1], int *word_number)
{
    char *p;
    int i = 0;
    char *sep = " ,.;:!?.-\n";

    p = strtok(str, sep);
    while (p != NULL)
    {
        if (strlen(p) > MAX_LEN_WORD)
            return WORD_OVERFLOW;

        strncpy(words[i], p, MAX_LEN_WORD + 1);
        i += 1;
        p = strtok(NULL, sep);
    }

    *word_number = i;

    return OK;
}
