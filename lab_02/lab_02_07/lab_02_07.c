#include <stdio.h>

#define N 10000

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

// Основная функция
int main()
{
    int arr[N];
    int index = 0, flag = 0;

    // Ввод элементов массива
    printf("Enter array elements:\n");
    int ch = scanf("%d", &arr[0]);

    if (ch != 1)
    {
        printf("Empty array.");
        return 1;
    }

    while (ch == 1)
    {
        index += 1;
        ch = scanf("%d", &arr[index]);

        if (index == N && ch != 1)
            break;

        if (index == N)
        {
            flag = 1;
            break;
        }
    }

    selection_sort(arr, index);

    // Вывод отсортированного массива
    printf("Sorted array:\n");
    for (int i = 0; i < index; i++)
    {
        printf("%d ", arr[i]);
    }

    if (flag == 1)
        return 100;
    else
        return 0;
}

