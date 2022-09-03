#include <stdio.h>

#define N 20

int enter_array(int *pa, int *len, int *pos_count)
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

        if (*pa > 0)
            *pos_count += 1;

        pa += 1;
    }

    return 0;
}

int reverse(int number)
{
    int result = number % 10;

    number /= 10;

    while (number > 0)
    {
        result *= 10;
        result += number % 10;
        number /= 10;
    }

    return result;
}

// Добавление реверса положительного элемента после этого элемента
int add_reverse_to_arr(int arr[], int len, int pos_count)
{
    int reverse_num, count = 0;

    for (int i = 0; i < len + pos_count; i++)
    {
        if (arr[i] > 0)
        {
            count += 1;
            reverse_num = reverse(arr[i]);

            // Сдвиг элементов
            for (int j = len + count; j > i; j--)
                arr[j] = arr[j - 1];

            arr[i + 1] = reverse_num;
            i += 1;
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
    int len, pos_count = 0;
    int ch;
    int arr[N], *parr = arr;

    ch = enter_array(parr, &len, &pos_count);

    if (ch == 1)
        return 1;

    if (pos_count != 0)
    {
        add_reverse_to_arr(arr, len, pos_count);
    }

    //Вывод массива
    printf("Changed array:\n");
    print_array(arr, len + pos_count);

    return 0;
}
