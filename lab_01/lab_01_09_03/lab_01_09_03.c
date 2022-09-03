#include <stdio.h>
#include <math.h>

float next(float x, int i)
{
    float next = 1 / (x + i);
    return next;
}

int main()
{
    float x = 0, g = 1;
    int i = 1, ch;

    printf("Enter numbers:\n");
    ch = scanf("%f", &x);

    if (ch != 1)
    {
        printf("Incorrect enter.");
        return 1;
    }

    if (x < 0)
    {
        printf("Empty enum");
        return 1;
    }

    while (x >= 0)
    {
        g *= next(x, i);
        i += 1;

        ch = scanf("%f", &x);

        if (ch != 1)
        {
            printf("Incorrect enter.");
            return 1;
        }
    }

    g = (float) exp(g);

    printf("Result:\n%f", g);

    return 0;
}
