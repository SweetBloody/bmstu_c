#include <stdio.h>
#include <math.h>

int main()
{
    float r1, r2, r3, r;

    printf("Enter three values of resistance:\n");
    scanf ("%f%f%f", &r1, &r2, &r3);

    r = r1 * r2 * r3 / (r2 * r3 + r1 * r3 + r1 * r2);

    printf("Total resistance:\n");
    printf("%f", r);

    return 0;
}
