#include "const.h" // Все константы, модули и функции

// Функция поиска двух максимумов
int process(FILE *f, int *max_1, int *max_2)
{
    int ch, number;

    ch = fscanf(f, "%d", &number);

    if (ch != 1)
        return NO_DATA;

    *max_1 = number;

    ch = fscanf(f, "%d", &number);

    if (ch != 1)
        return NO_TWO_MAX;

    if (number > *max_1)
    {
        *max_2 = *max_1;
        *max_1 = number;
    }
    else
        *max_2 = number;

    while (fscanf(f, "%d", &number) == 1)
    {
        if (number >= *max_1)
        {
            *max_2 = *max_1;
            *max_1 = number;
        }

        if (number > *max_2 && number < *max_1)
            *max_2 = number;
    }

    return OK;
}
