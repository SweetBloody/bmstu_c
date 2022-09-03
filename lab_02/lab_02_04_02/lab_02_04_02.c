#include <stdio.h>

#define N 10

int enter_array(int *pa, int *index, int *flag)
{
    // Ввод элементов массива
    printf("Enter array elements:\n");
    int ch = scanf("%d", pa);

    if (ch != 1)
    {
        printf("Empty array.");
        return 1;
    }

    while (ch == 1)
    {
        pa += 1;
        *index += 1;
        ch = scanf("%d", pa);

        if (*index == N && ch != 1)
            break;

        if (*index == N)
        {
            *flag = 1;
            break;
        }
    }

    return 0;
}

// Функция сортировки выбором
void selection_sort(int array[], int length)
{
    int min_index, t;

    for (int i = 0; i < length; i++)
    {
        min_index = i;

        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        t = array[i];
        array[i] = array[min_index];
        array[min_index] = t;
    }
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
    int arr[N], *parr = arr;
    int index = 0, flag = 0;

    int ch = enter_array(parr, &index, &flag);

    if (ch == 1)
        return 1;

    selection_sort(arr, index);

    // Вывод отсортированного массива
    printf("Sorted array:\n");
    print_array(arr, index);

    if (flag == 1)
        return 100;
    else
        return 0;
}
