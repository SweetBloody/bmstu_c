#include <stdio.h>
#include <math.h>

float approx_sum(float x, float eps)
{
    float sum = 1;
    int a = 1, b = 2;
    float next = a * x * x / b;

    while (fabs(next) >= eps)
    {
        sum += next;
        a += 2;
        b += 2;
        next = next * a * x * x / b;
    }

    return sum;
}

int main()
{
    float x;
    float eps;
    int ch;
    float s;
    double f;
    double delta, sigma;

    printf("Enter x:\n");
    ch = scanf("%f", &x);
    printf("Enter eps:\n");
    ch += scanf("%f", &eps);

    if (ch != 2)
    {
        printf("Incorrect enter.");
        return 1;
    }

    if (eps <= 0 || eps > 1)
    {
        printf("Incorrect eps value.");
        return 1;
    }

    if (fabs(x) >= 1)
    {
        printf("Incorrect x value.");
        return 1;
    }

    s = approx_sum(x, eps);
    f = 1 / sqrt(1 - x * x);
    delta = fabs(f - s);
    sigma = fabs(f - s) / fabs(f);

    printf("Approximate sum: %f\n", s);
    printf("Accurate sum: %lf\n", f);
    printf("Delta: %lf\n", delta);
    printf("Sigma: %lf\n", sigma);

    return 0;
}
