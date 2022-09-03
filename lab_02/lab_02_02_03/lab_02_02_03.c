#include <stdio.h>
#include <math.h>

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

/* Функция, определяющая является ли число
числом Армстронга*/
int is_armstrong(int number)
{
    int num_length = 0;
    int number_1 = number, number_2 = number;
    int result = 0;

    if (number == 0)
        return 0;

    while (number_1 > 9)
    {
        num_length += 1;
        number_1 /= 10;
    }

    num_length += 1;

    while (number_2 > 0)
    {
        result += (int) pow(number_2 % 10, num_length);
        number_2 /= 10;
    }

    if (result == number)
        return 1;
    else
        return 0;
}

// Создание нового массива из чисел Армстронга
int armstrong_array(int arr[], int len, int new_arr[], int *new_len)
{
    for (int i = 0; i < len; i++)
    {
        if (is_armstrong(arr[i]) == 1)
        {
            new_arr[*new_len] = arr[i];
            *new_len += 1;
        }
    }

    return 0;
}

int print_array(int arr[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Основная функция
int main()
{
    int len, new_len = 0;
    int arr[N], *parr = arr, new_arr[N];

    int ch = enter_array(parr, &len);

    if (ch == 1)
        return 1;

    armstrong_array(arr, len, new_arr, &new_len);

    // Вывод массива
    if (new_len == 0)
    {
        printf("There are no Armstrong numbers in the array.\n");
        return 1;
    }
    else
    {
        printf("Array with Armstrong numbers:\n");
        print_array(new_arr, new_len);
    }

    return 0;
}
