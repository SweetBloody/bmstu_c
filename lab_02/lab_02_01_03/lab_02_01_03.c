#include <stdio.h>
#include <math.h>

#define N 10

int enter_array(int *pa, int *len)
{
    int flag = 0, ch;

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

        if (*pa > 0)
            flag = 1;

        pa += 1;
    }

    if (flag == 0)
    {
        printf("Every element is negative.");
        return 1;
    }

    return 0;
}

float average_geom_value(int array[], int length)
{
    float result = 1;
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (array[i] > 0)
        {
            count += 1;
            result *= array[i];
        }
    }

    result = powf(result, (float) 1 / count);
    return result;
}

int main()
{
    int len = 0;
    int arr[N], *parr = arr;
    float res;

    int ch = enter_array(parr, &len);

    if (ch == 1)
        return 1;

    res = average_geom_value(arr, len);

    printf("Average geometry value of positive elements:\n%f", res);

    return 0;
}

