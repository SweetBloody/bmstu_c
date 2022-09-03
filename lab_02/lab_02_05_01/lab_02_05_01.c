#include <stdio.h>

#define N 10

int enter_array(int *pa, int *len)
{
    int ch;

    printf("Enter the length of array:\n");
    ch = scanf("%d", len);

    if (ch != 1)
    {
        printf("Incorrect enter.");
        return 1;
    }

    if (*len <= 0 || *len > 10)
    {
        printf("Wrong length value.");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < *len; i++)
    {
        ch = scanf("%d", pa);
        if (ch != 1)
        {
            printf("Incorrect enter.");
            return 1;
        }

        pa += 1;
    }

    return 0;
}

int func(int *arr, int *pa, int *pa_n)
{
    int sum = 0, count_pos = 0, count_neg = 0, min;
    int len = pa_n - pa;

    for (int i = 0; i < len; i++)
    {
        if (*pa > 0)
            count_pos += 1;

        if (*pa < 0)
            count_neg += 1;

        pa += 1;
    }

    if (count_neg < count_pos)
        min = count_neg;
    else
        min = count_pos;

    pa = arr;
    pa_n = pa + len - 1;
    for (int i = 0; i < min; i++)
    {
        while (*pa >= 0)
            pa += 1;

        while (*pa_n <= 0)
            pa_n -= 1;

        sum += *pa * *pa_n;
        pa += 1;
        pa_n -= 1;
    }

    return sum;
}

int main()
{
    int arr[N], *pa = arr, *pa_n;
    int len, sum;

    int ch = enter_array(pa, &len);

    if (ch == 1)
        return 1;

    pa = arr;
    pa_n = pa + len;
    sum = func(arr, pa, pa_n);

    if (sum == 0)
    {
        printf("There are no positive or negative elements.");
        return 1;
    }
    else
    {
        printf("sum = %d\n", sum);
        return 0;
    }
}
