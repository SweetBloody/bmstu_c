#include <string.h>
#include "word_change.h"
#include "const.h" // Константы

// Функция, оставляющая только первые вхождения букв в слове
int word_change(char *word)
{
    int len = strlen(word), count = 0;

    for (int i = 1; i < len - count; i++)
        for (int j = 0; j < i; j++)
            if (word[j] == word[i])
            {
                for (int k = i; k < len - count; k++)
                    word[k] = word[k + 1];

                count += 1;
                i -= 1;
                break;
            }

    return OK;
}
