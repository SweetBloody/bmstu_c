#include <stdio.h>
#include <string.h>
#include "word_change.h" // Функция, оставляющая только первые вхождения букв в слове
#include "const.h" // Константы

// Функция, составляющая результирующую строку из измененных слов
int result_string(char words[][MAX_LEN_WORD + 1], char *str, int words_number)
{
    int index = 0;

    for (int i = words_number - 2; i >= 0; i--)
        if (strcmp(words[i], words[words_number - 1]) != 0)
        {
            word_change(words[i]);

            if (index != 0)
            {
                str[index] = ' ';
                index += 1;
            }

            for (int j = 0; j < (int) strlen(words[i]); j++)
            {
                str[index] = words[i][j];
                index += 1;
            }
        }

    str[index] = '\0';

    if (strlen(str) != 0)
        printf("Result: %s", str);

    return OK;
}
