#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define n 10000
#define N 1000

int process_1(int arr[], int len)
{
    int sum = 0, count_pos = 0, count_neg = 0, min;
    int neg = 0, pos = len - 1;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] > 0)
            count_pos += 1;

        if (arr[i] < 0)
            count_neg += 1;
    }

    if (count_neg < count_pos)
        min = count_neg;
    else
        min = count_pos;

    for (int i = 0; i < min; i++)
    {
        while (arr[neg] >= 0)
            neg += 1;

        while (arr[pos] <= 0)
            pos -= 1;

        sum += arr[pos] * arr[neg];
        neg += 1;
        pos -= 1;
    }

    return sum;
}

int process_2(int *arr, int len)
{
    int sum = 0, count_pos = 0, count_neg = 0, min;
    int neg = 0, pos = len - 1;

    for (int i = 0; i < len; i++)
    {
        if (*(arr + i) > 0)
            count_pos += 1;

        if (*(arr + i) < 0)
            count_neg += 1;
    }

    if (count_neg < count_pos)
        min = count_neg;
    else
        min = count_pos;

    for (int i = 0; i < min; i++)
    {
        while (*(arr + neg) >= 0)
            neg += 1;

        while (*(arr + pos) <= 0)
            pos -= 1;

        sum += *(arr + pos) * *(arr + neg);
        neg += 1;
        pos -= 1;
    }

    return sum;
}

int process_3(int *arr, int *pa, int *pa_n)
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
    int a[n], b[n], *pa = a, *pa_n;
    int na, nb;
    int sum_1, sum_2, sum_3;
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time;

    // Ввод количества элементов массива
    printf("Enter the length of array:\n");
    int ch = scanf("%d", &na);

    if (ch != 1)
    {
        printf("Incorrect enter.");
        return 1;
    }

    if (na <= 0 || na > n)
    {
        printf("Incorrect value of length.");
        return 1;
    }

    // Формирование массива
    for (int i = 0; i < na; i++)
    {
        *pa = rand() % 100 - 50;
        pa += 1;
    }

    printf("Time:\n");

    // Подсчет времени 1
    printf("Process 1.\n");
    elapsed_time = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < na; j++)
            b[j] = a[j];
        nb = na;

        gettimeofday(&tv_start, NULL);
        sum_1 = process_1(b, nb);
        gettimeofday(&tv_stop, NULL);

        elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                (tv_stop.tv_usec - tv_start.tv_usec);
    }

    printf("%" PRId64 " us\n", elapsed_time / N);

    // Подсчет времени 2
    printf("Process 2.\n");
    elapsed_time = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < na; j++)
            b[j] = a[j];
        nb = na;

        gettimeofday(&tv_start, NULL);
        sum_2 = process_2(b, nb);
        gettimeofday(&tv_stop, NULL);

        elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                (tv_stop.tv_usec - tv_start.tv_usec);
    }

    printf("%" PRId64 " us\n", elapsed_time / N);

    // Подсчет времени 3
    printf("Process 3.\n");
    pa = a;
    pa_n = pa + na;
    elapsed_time = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < na; j++)
            b[j] = a[j];

        gettimeofday(&tv_start, NULL);
        sum_3 = process_3(b, pa, pa_n);
        gettimeofday(&tv_stop, NULL);

        elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                (tv_stop.tv_usec - tv_start.tv_usec);
    }

    printf("%" PRId64 " us\n", elapsed_time / N);

    if (sum_1 == 0 && sum_2 == 0 && sum_3 == 0)
    {
        printf("There are no positive or negative elements.");
        return 1;
    }
    else
    {
        printf("sum1 = %d\n", sum_1);
        printf("sum2 = %d\n", sum_2);
        printf("sum3 = %d\n", sum_3);
        return 0;
    }
}
