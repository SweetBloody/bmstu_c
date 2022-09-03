#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, x3, y3;
    float p;

    scanf ("%f%f", &x1, &y1);
    scanf ("%f%f", &x2, &y2);
    scanf ("%f%f", &x3, &y3);

    p = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) + sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    printf("%f", p);

    return 0;
}
