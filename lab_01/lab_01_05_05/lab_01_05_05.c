#include <stdio.h>
#include <math.h>

void figures(long long int a, int len)
{
    int fig;
    long long int b;

    b = pow(10, len - 1);

    while (a > 9)
    {
        fig = a / b;
        printf("%d", fig);
        a = a % b;
        b = b / 10;
    }

    printf("%lld", a);
}

int main()
{
    long long int n, n_count;
    int len = 0;
    int rc = scanf("%lld", &n);

    if (rc != 1)
        return 1;
    else
    {
        if (n < 1)
            return 1;
        else
        {
            if (n > 0 && n < 10)
                printf("%lld", n);
            else
            {
                n_count = n;

                while (n_count > 9)
                {
                    n_count = n_count / 10;
                    len += 1;
                }

                len += 1;

                figures(n, len);
            }
        }
    }
    return 0;
}
