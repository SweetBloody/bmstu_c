#include "const.h" // Все константы, модули и функции

// Функция нахождения индексов минимума и максимума
int find_min_max(char **argv, int *min_ind, int *max_ind)
{
    int ch, index = 0;
    double number, min, max;
    FILE *f = fopen(argv[2], "r");

    ch = fscanf(f, "%lf", &number);

    if (ch != 1)
    {
        fclose(f);
        return NO_DATA;
    }

    min = number;
    max = number;
    *min_ind = index;
    *max_ind = index;

    while (!feof(f))
    {
        ch = fscanf(f, "%lf", &number);
        index += 1;

        if (ch != 1 && ch != EOF)
        {
            fclose(f);
            return INCORRECT_INPUT;
        }

        if (number > max)
        {
            max = number;
            *max_ind = index;
        }

        if (number < min)
        {
            min = number;
            *min_ind = index;
        }
    }

    fclose(f);

    return OK;
}

// Функция нахождения сренего значения чисел, расположенных между
// минимумом и максимумом
double find_avg(char **argv, int min_ind, int max_ind)
{
    int index = 0;
    double number, avg = 0;
    FILE *f = fopen(argv[2], "r");

    if (abs(min_ind - max_ind) == 1)
        return 0;

    fscanf(f, "%lf", &number);

    while (index != min_ind && index != max_ind)
    {
        fscanf(f, "%lf", &number);
        index += 1;
    }

    index += 1;

    while (index != min_ind && index != max_ind)
    {
        fscanf(f, "%lf", &number);
        avg += number;
        index += 1;
    }

    avg = avg / (abs(min_ind - max_ind) - 1);

    fclose(f);

    return avg;
}
