#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define N 1000

// Компаратор целых чисел
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

// Замена местами двух элементов
void swap_elems(char *elem1, char *elem2, size_t size)
{
    char tmp;

    for (int i = 0; i < (int) size; i++)
    {
        tmp = *elem1;
        *elem1 = *elem2;
        *elem2 = tmp;

        elem1 += 1;
        elem2 += 1;
    }
}

// Сортировка выбором
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    char *end = (char *) first + (number - 1) * size;
    char *max, *pa_j, *pa_i;

    for (int i = number; i > 0; i--)
    {
        pa_i = end - (number - i) * size;
        max = pa_i;
        pa_j = end - size * (number - i + 1);
        for (int j = i - 1; j > 0; j--)
        {
            if (comparator((void *) pa_j, (void *) max) > 0)
                max = pa_j;

            pa_j -= size;
        }

        swap_elems(max, pa_i, size);
    }
}

// Вывод чисел из массива в файл
void print_array(int *array_st, int *array_end)
{

    while (array_st < array_end)
    {
        fprintf(stdout, "%d ", *array_st);
        array_st += 1;
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    int ch, *array_1, *array_2;

    int na, nb;
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time;

    // Ввод количества элементов массива
    printf("Enter the length of array:\n");
    ch = scanf("%d", &na);

    if (ch != 1)
    {
        printf("Incorrect enter.");
        return 1;
    }

    if (na <= 0)
    {
        printf("Incorrect value of length.");
        return 1;
    }

    array_1 = malloc(na * sizeof(int));
    array_2 = malloc(na * sizeof(int));

    int *array_1_st = array_1, *array_2_st = array_2;

    // Формирование массива рандом
//    for (int i = 0; i < na; i++)
//    {
//        *array_1_st = rand() % 100 - 50;
//        *array_2_st = *array_1_st;
//        array_1_st += 1;
//        array_2_st += 1;
//    }

//    // Формирование массива одинаковые
//    for (int i = 0; i < na; i++)
//    {
//        *array_1_st = 5;
//        *array_2_st = *array_1_st;
//        array_1_st += 1;
//        array_2_st += 1;
//    }

    // Формирование массива отсортированы
    for (int i = 0; i < na; i++)
    {
        *array_1_st = i;
        *array_2_st = *array_1_st;
        array_1_st += 1;
        array_2_st += 1;
    }

//    print_array(array_1, array_1 + na);
//    print_array(array_2, array_2 + na);


    printf("Time:\n");

    // Подсчет времени 1
    printf("Mysort.\n");
    elapsed_time = 0;
    for (int i = 0; i < N; i++)
    {
        gettimeofday(&tv_start, NULL);
        mysort(array_1, na, sizeof(int), compare_int);
        gettimeofday(&tv_stop, NULL);

        elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                        (tv_stop.tv_usec - tv_start.tv_usec);
    }

    printf("%" PRId64 " us\n", elapsed_time / N);

    // Подсчет времени 2
    printf("Qsort.\n");
    elapsed_time = 0;
    for (int i = 0; i < N; i++)
    {
        gettimeofday(&tv_start, NULL);
        qsort(array_2, na, sizeof(int), compare_int);
        gettimeofday(&tv_stop, NULL);

        elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                        (tv_stop.tv_usec - tv_start.tv_usec);
    }

    printf("%" PRId64 " us\n", elapsed_time / N);

//    print_array(array_1, array_1 + na);
//    print_array(array_2, array_2 + na);

    return ch;
}

