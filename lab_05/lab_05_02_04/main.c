#include "const.h"

int main(int argc, char **argv)
{
    int ch;
    int min_ind, max_ind;
    double avg;

    ch = find_min_max(argv, &min_ind, &max_ind);

    if (ch == NO_DATA)
    {
        printf("No data\n");
        return ch;
    }

    if (ch == INCORRECT_INPUT)
    {
        printf("Incorrect input\n");
        return ch;
    }

    avg = find_avg(argv, min_ind, max_ind);

    printf("Average: %lf\n", avg);

    return ch;
}
